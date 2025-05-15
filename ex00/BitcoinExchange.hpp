/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 01:05:29 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/15 15:37:52 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP
# include <fstream>
# include <map>

static std::map<unsigned long long, double> values;

class BitcoinExchange
{
	public:
		static bool loadValues();
		static void translateValues(std::ifstream input);
};

#endif