/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 02:58:35 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/20 03:15:16 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <cstdlib>

void printVector(std::vector<int> &vec)
{
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << (it + 1 != vec.end() ? " " : "");
	if (vec.size())
		std::cout << std::endl;
}

bool isValid(const char *value)
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
