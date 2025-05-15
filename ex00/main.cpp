/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 01:07:01 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/15 17:56:53 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "colors.hpp"
#include <fstream>
#include <iostream>
#include <map>

int main(int ac, char **av)
{
	std::ifstream infile;

	if (ac != 2)
	{
		std::cout << RED << "You need to specify a database file." << RESET << std::endl;
		return (1);
	}
	infile.open(av[1]);
	if (infile.fail())
	{
		std::cout << RED << "Can't open " << av[1] << ". Aborting." << RESET << std::endl;
		return (2);
	}
	if (!BitcoinExchange::loadValues())
		return (3);
	BitcoinExchange::translateValues(infile);
}
