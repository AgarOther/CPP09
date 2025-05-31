/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 23:58:03 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/31 11:16:52 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "colors.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac < 3)
	{
		std::cerr << RED << "You need to specify at least 2 different positive integers." << RESET << std::endl;
		return (1);
	}
	if (!PmergeMe::execute((const char **)&av[1]))
		return (2);
}
