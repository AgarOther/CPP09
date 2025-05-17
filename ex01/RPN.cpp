/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:40:15 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/17 18:00:55 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "colors.hpp"
#include <sstream>
#include <iostream>
#include <cstdlib>

static bool isValid(const char &c)
{
	return (isdigit(c) || c == '+' || c == '-' || c == '/' || c == '*');
}

static double executeOperation(double res, char digit, char operand)
{
	if (operand == '+')
		return (res + atoi(&digit));
	else if (operand == '-')
		return (res - atoi(&digit));
	else if (operand == '*')
		return (res * atoi(&digit));
	else if (operand == '/')
		return (res / atoi(&digit));
	else
		return (-1);
}

void RPN::processValues()
{
	double res = 0;
	std::vector<char>::iterator valuesIter = values.begin();
	std::vector<char>::iterator operandsIter = operands.begin();

	for (; valuesIter != values.end(); valuesIter++)
	{
		if (!res)
		{
			char digit = *valuesIter;
			res = atoi(&digit);
			continue;
		}
		res = executeOperation(res, *valuesIter, *operandsIter);
		operandsIter++;
	}
	std::cout << res << std::endl;
}

bool RPN::loadValues(const std::string &str)
{
	std::stringstream split(str);
	std::string tmp;
	int count;

	count = 1;
	while (std::getline(split, tmp, ' '))
	{
		if (tmp.length() != 1 || !isValid(tmp[0]))
		{
			if (tmp.length() == 0)
				std::cout << RED << "Value #" << count << " has multiple spaces." << RESET << std::endl;
			else
				std::cout << RED << "Value #" << count <<" '" << BLUE << tmp << RED << "' isn't valid. It needs to be 1 character, either digit or operand." << RESET << std::endl;
			return (false);
		}
		if (isdigit(tmp[0]))
			values.push_back(tmp[0]);
		else
			operands.push_back(tmp[0]);
		count++;
	}
	if (values.size() < 2)
	{
		std::cout << RED << "Not enough values. You need to have at least 2 before any operands." << RESET << std::endl;
		return (false);
	}
	else if (operands.size() < 1)
	{
		std::cout << RED << "Not enough operands. You need to have at least 1 after the first 2 values." << RESET << std::endl;
		return (false);
	}
	else if (operands.size() >= values.size())
	{
		std::cout << RED << "Not enough values for the amount of operands. You need to have at most 1 less operand than the total amount of values." << RESET << std::endl;
		return (false);
	}
	return (true);
}
