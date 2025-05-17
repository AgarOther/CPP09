/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 01:07:01 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/17 23:36:39 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "colors.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << RED << "You need to input your RPN as a single argument." << RESET << std::endl;
		return (1);
	}
	if (!RPN::execute(av[1]))
		return (2);
}
