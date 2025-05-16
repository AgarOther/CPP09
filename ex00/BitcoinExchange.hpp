/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 01:05:29 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/16 13:08:46 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP
# include <fstream>
# include <map>
# include <ctime>

static std::map<time_t, float> values;

class BitcoinExchange
{
	public:
		static bool loadValues();
		static void translateValues(std::ifstream &input);
		static float getValue(time_t timestamp);
};

#endif