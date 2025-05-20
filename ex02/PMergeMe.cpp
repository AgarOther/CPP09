/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 23:59:09 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/20 03:20:48 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"
#include "colors.hpp"
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>

bool PMergeMe::execute(const char **str)
{
	long tmp;
	clock_t vectorTime;
	clock_t dequeTime;
	clock_t tmpTime;

	for (int i = 0; str[i]; i++)
	{
		if (!isValid(str[i]))
		{
			if (str[i] && str[i][0] == '-')
				std::cerr << RED << "Value #" << i + 1 << " '" << BOLD_RED << str[i] << RESET << RED << "' is negative. Only positive integers are allowed."
					<< RESET << std::endl;
			else
				std::cerr << RED << "Value #" << i + 1 << " '" << BOLD_RED << str[i] << RESET << RED << "' is invalid." << RESET << std::endl;
			return (false);
		}
		tmp = atol(str[i]);
		if (tmp > __INT_MAX__)
		{
			std::cerr << RED << "Value #" << i + 1 << " '" << BOLD_RED << str[i] << RESET << RED << "' is an integer overflow." << RESET << std::endl;
			return (false);
		}
		else if (isDuplicate(vectorSequence, tmp))
		{
			std::cerr << RED << "Value #" << i + 1 << " '" << BOLD_RED << str[i] << RESET << RED << "' is a duplicate." << RESET << std::endl;
			return (false);
		}
		vectorSequence.push_back((int)tmp);
		dequeSequence.push_back((int)tmp);
	}
	if (isSorted(vectorSequence))
	{
		std::cerr << YELLOW << "Your values are already sorted." << RESET << std::endl;
		return (false);
	}
	std::cout << "Before:\t";
	printVector(vectorSequence);

	vectorTime = clock();
	std::vector<int> sortedVector = fordJohnson(vectorSequence);
	tmpTime = clock();
	vectorTime = tmpTime - vectorTime;

	dequeTime = clock();
	std::deque<int> sorteddeque = fordJohnson(dequeSequence);
	tmpTime = clock();
	dequeTime = tmpTime - dequeTime;

	std::cout << "After:\t";
	printVector(sortedVector);

	double passedVectorTime = static_cast<double>(vectorTime) / CLOCKS_PER_SEC * 1000;
	double passedDequeTime = static_cast<double>(dequeTime) / CLOCKS_PER_SEC * 1000;
	std::cout << "Time to process a range of " << vectorSequence.size() << " elements with std::vector\t:\t" << passedVectorTime << "ms" << std::endl;
	std::cout << "Time to process a range of " << vectorSequence.size() << " elements with std::deque\t:\t" << passedDequeTime << "ms" << std::endl;
	return (true);
}
