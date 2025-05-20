/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 23:58:40 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/20 03:16:59 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <vector>
# include <deque>

static std::vector<int> vectorSequence;
static std::deque<int> dequeSequence;

class PMergeMe
{
	public:
		static bool execute(const char **str);
};

void printVector(std::vector<int> &vec);
bool isValid(const char *value);

#include "PMergeMe.tpp"

#endif