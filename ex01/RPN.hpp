/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:39:50 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/17 23:45:02 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <stack>
# include <string>

static std::stack<double> values;

class RPN
{
	public:
		static bool execute(const std::string &str);
		static void processValues(const std::string &str);
		static double executeOperation(double leftOperand, double rightOperand, char operand);
};

#endif