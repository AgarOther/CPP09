/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 23:58:40 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/18 14:50:32 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <vector>
# include <list>

static std::vector<int> vectorSequence;
static std::list<int> listSequence;

class PMergeMe
{
	public:
		static bool parseValues(const char **str);

		template <typename T>
		void sort(T);
};

#endif