/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 23:59:09 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/18 14:37:45 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"
#include "colors.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

static bool isValid(const char *value)
{
	int length = 0;
	bool isValue = false;

	for (int i = 0; value[i]; i++)
	{
		if (value[i] == '-')
			return (false);
		if (i && !isdigit(value[i]))
			return (false);
		else if (!i && value[i] != '+' && !isdigit(value[i]))
			return (false);
		if (isdigit(value[i]) && value[i] != '0')
			isValue = true;
		if (isValue)
			length++;
	}
	if (length > 11)
		return (false);
	return (true);
}

static bool isDuplicate(int n)
{
	for (std::vector<int>::iterator it = vectorSequence.begin(); it != vectorSequence.end(); it++)
	{
		if (*it == n)
			return (true);
	}
	return (false);
}

static bool isSorted()
{
	int tmp;

	for (std::vector<int>::iterator it = vectorSequence.begin(); it != vectorSequence.end(); it++)
	{
		if (it == vectorSequence.begin())
		{
			tmp = *it;
			continue;
		}
		if (tmp > *it)
			return (false);
		tmp = *it;
	}
	return (true);
}

void PMergeMe::parseValues(const char **str)
{
	long tmp;

	for (int i = 0; str[i]; i++)
	{
		if (!isValid(str[i]))
		{
			std::cerr << RED << "Value #" << i + 1 << " '" << BOLD_RED << str[i] << RESET << RED << "' is invalid." << std::endl;
			return;
		}
		tmp = atol(str[i]);
		if (tmp > __INT_MAX__)
		{
			std::cerr << RED << "Value #" << i + 1 << " '" << BOLD_RED << str[i] << RESET << RED << "' is an integer overflow." << std::endl;
			return;
		}
		else if (isDuplicate(tmp))
		{
			std::cerr << RED << "Value #" << i + 1 << " '" << BOLD_RED << str[i] << RESET << RED << "' is a duplicate." << std::endl;
			return;
		}
		vectorSequence.push_back((int)tmp);
		listSequence.push_back((int)tmp);
	}
	if (isSorted())
	{
		std::cerr << YELLOW << "Your values are already sorted." << std::endl;
		return;
	}
}
