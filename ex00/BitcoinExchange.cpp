/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 01:06:48 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/18 00:14:16 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "colors.hpp"
#include <iostream>
#include <string>
#include <algorithm>

static bool isStringValid(const std::string &str)
{
	size_t dashes;
	size_t dots;

	if (std::find(str.begin(), str.end(), ',') == str.end())
		return (false);
	dashes = 0;
	dots = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]) && str[i] != '-' && str[i] != ',' && str[i] != '.')
			return (false);
		else if ((str[i] == '-' && (i != 4 && i != 7)) || (str[i] == ',' && i != 10))
			return (false);
		else if (str[i] == ',' && i == str.length() - 1)
			return (false);
		if (str[i] == '-')
			dashes++;
		else if (str[i] == '.')
			dots++;
	}
	return (std::find(str.begin(), str.end(), ',') != str.end() && dashes == 2 && dots <= 1);
}

static time_t dateToTimestamp(const std::string &date)
{
	struct tm time;

	time.tm_year = atoi(date.substr(0, 4).c_str()) - 1900;
	time.tm_mon = atoi(date.substr(5, 2).c_str());
	time.tm_mday = atoi(date.substr(8, 2).c_str());
	time.tm_hour = 0;
	time.tm_min = 0;
	time.tm_sec = 0;
	time.tm_isdst = false;
	return (mktime(&time));
}

static bool isLeapYear(short year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

static bool isDateValid(const std::string &date)
{
	short year;
	short month;
	short day;

	year = atoi(date.substr(0, 4).c_str());
	month = atoi(date.substr(5, 2).c_str());
	day = atoi(date.substr(8, 2).c_str());
	if (!month || month > 12 || !day || day > 31 || (month == 2 && day > 29))
		return (false);
	else if (month != 1 && month != 3 && month != 5 && month != 7 && month != 8 && month != 10 && month != 12 && day == 31)
		return (false);
	else if (month == 2 && day == 29 && !isLeapYear(year))
		return (false);
	return (true);
}

bool BitcoinExchange::loadValues()
{
	std::ifstream database;
	std::string buffer;
	size_t line;
	
	database.open("data.csv");
	if (database.fail())
	{
		std::cerr << RED << "Can't open data.csv. Aborting." << RESET << std::endl;
		return (false);
	}
	line = false;
	while (std::getline(database, buffer))
	{
		if (!line)
		{
			if (buffer != "date,exchange_rate")
			{
				std::cerr << RED << "data.csv missing or corrupted first line indicator. Should be \"date,exchange_rate\"." << std::endl;
				std::cerr << "> " << buffer << RESET << std::endl;
				return (false);
			}
			line++;
			continue;
		}
		if (!isStringValid(buffer))
		{
			std::cerr << RED << "data.csv is corrupted at line " << line + 1 << "." << std::endl;
			std::cerr << "> " <<  buffer << RESET << std::endl;
			return (false);
		}
		else if (!isDateValid(buffer.substr(0, 11)))
		{
			std::cerr << RED << "data.csv has invalid date at line " << line + 1 << "." << std::endl;
			std::cerr << "> " <<  buffer << RESET << std::endl;
			return (false);
		}
		values.insert(std::pair<time_t, float>(dateToTimestamp(buffer), atof(buffer.substr(11, buffer.length() - 11).c_str())));
		line++;
	}
	database.close();
	std::cout << GREEN << "Parsed data.csv successfully." << RESET << std::endl;
	return (true);
}

static bool isValueValid(const std::string &str)
{
	size_t dashes;
	size_t dots;

	if (std::find(str.begin(), str.end(), '|') == str.end())
		return (false);
	dashes = 0;
	dots = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]) && str[i] != '-' && str[i] != '|' && str[i] != '.' && str[i] != ' ')
			return (false);
		else if ((str[i] == '-' && (i != 4 && i != 7 && i != 13)) || (str[i] == '|' && i != 11) || (str[i] != ' ' && (i == 10 || i == 12)))
			return (false);
		if (str[i] == '-')
			dashes++;
		else if (str[i] == '.')
			dots++;
	}
	return (std::find(str.begin(), str.end(), '|') != str.end() && (dashes == 2 || dashes == 3) && dots <= 1);
}

float BitcoinExchange::getValue(time_t timestamp)
{
	time_t tmp = 0;
	time_t tmp_before = 0;

	for (std::map<time_t, float>::iterator it = values.begin(); it != values.end(); it++)
	{
		if (tmp >= timestamp)
		{
			if (tmp == timestamp)
				return (values[tmp]);
			return (values[tmp_before]);
		}
		tmp_before = tmp;
		tmp = it->first;
	}
	return (-1);
}

void BitcoinExchange::translateValues(std::ifstream &input)
{
	std::string buffer;
	size_t line;

	line = false;
	while (std::getline(input, buffer))
	{
		if (!line)
		{
			if (buffer != "date | value")
			{
				std::cerr << RED << "Input file missing or corrupted first line indicator. Should be \"date | value\"." << std::endl;
				std::cerr << "> " << buffer << RESET << std::endl;
			}
			line++;
			continue;
		}
		if (!isValueValid(buffer))
		{
			std::cerr << RED << "Input file is corrupted at line " << line + 1 << "." << std::endl;
			std::cerr << "> " <<  buffer << RESET << std::endl;
			line++;
			continue ;
		}
		else if (!isDateValid(buffer.substr(0, 11)))
		{
			std::cerr << RED << "Input file has invalid date at line " << line + 1 << "." << std::endl;
			std::cerr << "> " <<  buffer << RESET << std::endl;
			continue;
		}
		float value = getValue(dateToTimestamp(buffer.substr(0, 10)));
		if (value < 0)
		{
			std::cerr << RED << "Input file has invalid value at line " << line + 1 << "." << std::endl;
			std::cerr << "> " << buffer << RESET << std::endl;
			line++;
			continue;
		}
		float amount = atof(buffer.substr(13, buffer.length() - 13).c_str());
		if (amount > 1000 || amount < 0)
		{
			if (amount > 1000)
				std::cerr << RED << "Input file value is too large at line " << line + 1 << ". It must be between 0 and 1000." << std::endl;
			else
				std::cerr << RED << "Input file value is negative at line " << line + 1 << ". It must be between 0 and 1000." << std::endl;	
			std::cerr << "> " << buffer << RESET << std::endl;
			line++;
			continue;
		}
		std::cout << buffer.substr(0, 10) << " => " << amount << " = " << value * amount << std::endl;
		line++;
	}
	input.close();
}
