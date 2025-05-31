/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:40:15 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/31 11:25:50 by scraeyme         ###   ########.fr       */
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

double RPN::executeOperation(double leftOperand, double rightOperand, char operand)
{
	if (operand == '+')
		return (leftOperand + rightOperand);
	else if (operand == '-')
		return (leftOperand - rightOperand);
	else if (operand == '*')
		return (leftOperand * rightOperand);
	else if (operand == '/')
		return (leftOperand / rightOperand);
	else
		return (-1);
}

void RPN::processValues(const std::string &str)
{
	double leftOperand = 0;
	double rightOperand = 0;
	double tmp = 0;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]))
			values.push(atoi(&str[i]));
		else if (str[i] != ' ')
		{
			rightOperand = values.top();
			values.pop();
			if (values.empty())
			{
				std::cerr << RED << "Invalid RPN expression." << RESET << std::endl;
				return;
			}
			leftOperand = values.top();
			values.pop();
			if (!rightOperand)
			{
				std::cerr << RED << "Zero division detected. Aborting." << RESET << std::endl;
				while (values.size())
					values.pop();
				return;
			}
			tmp = executeOperation(leftOperand, rightOperand, str[i]);
			values.push(tmp);
		}
	}
	tmp = values.top();
	values.pop();
	if (values.empty())
		std::cout << tmp << std::endl;
	else
	{
		std::cerr << RED << "Invalid RPN expression. Too many values specified for the amount of operands." << RESET << std::endl;
		while (!values.empty())
			values.pop();
	}
}

bool RPN::execute(const std::string &str)
{
	std::stringstream split(str);
	std::string tmp;
	int count;
	int values;
	int operands;

	count = 1;
	values = 1;
	operands = 1;
	while (std::getline(split, tmp, ' '))
	{
		if (tmp.length() != 1 || !isValid(tmp[0]))
		{
			if (tmp.length() == 0)
				std::cerr << RED << "Value #" << count << " has multiple spaces." << RESET << std::endl;
			else
				std::cerr << RED << "Value #" << count <<" '" << BOLD_RED << tmp << RESET << RED
					<< "' isn't valid. It needs to be 1 character, either digit or operand." << RESET << std::endl;
			return (false);
		}
		if (isdigit(tmp[0]))
			values++;
		else
			operands++;
		count++;
	}
	if (values < 2)
	{
		std::cerr << RED << "Not enough values. You need to have at least 2 before any operands." << RESET << std::endl;
		return (false);
	}
	else if (operands < 1)
	{
		std::cerr << RED << "Not enough operands. You need to have at least 1 after the first 2 values." << RESET << std::endl;
		return (false);
	}
	else if (operands >= values)
	{
		std::cerr << RED << "Not enough values for the amount of operands. You need to have at most 1 less operand than the total amount of values."
			<< RESET << std::endl;
		return (false);
	}
	processValues(str);
	return (true);
}
