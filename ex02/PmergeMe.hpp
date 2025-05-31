/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 23:58:40 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/31 11:17:15 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <vector>
# include <deque>

static std::vector<int> vectorSequence;
static std::deque<int> dequeSequence;

class PmergeMe
{
	public:
		static bool execute(const char **str);
};

void printVector(std::vector<int> &vec);
bool isValid(const char *value);

#include "PmergeMe.tpp"

#endif