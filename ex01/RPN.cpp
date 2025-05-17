/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:40:15 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/17 10:26:16 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "colors.hpp"
#include <sstream>
#include <iostream>

static bool isValid(const char &c)
{
	return (isdigit(c) || c == '+' || c == '-' || c == '/' || c == '*');
}

void RPN::loadValues(const std::string &str)
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
			return;
		}
		values.push_back(tmp[0]);
		count++;
	}
}
