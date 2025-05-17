/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:39:50 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/17 17:44:10 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <vector>
# include <string>

static std::vector<char> values;
static std::vector<char> operands;

class RPN
{
	public:
		static bool loadValues(const std::string &str);
		static void processValues();
};

#endif