/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:44:44 by saeby             #+#    #+#             */
/*   Updated: 2023/04/24 19:58:20 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP
# include <map>
# include <iostream>
# include <fstream>
# include <sstream>

class BitcoinExchange
{
	public:
		BitcoinExchange(std::string dataFName);
		BitcoinExchange(const BitcoinExchange& be);
		BitcoinExchange	&operator=(const BitcoinExchange& be);
		~BitcoinExchange();

		std::map<std::string, float>	getRates(void) const;
		bool							validDate(std::string d) const;
		bool							validValue(float v) const;
		float							getRate(const std::string &d) const;
		std::string						getFname(void) const;

		class	UnknownDataFileException : public std::exception
		{
			virtual const char *what(void) const throw()
			{
				return ("Unable to open data file.");
			}
		};
		class UnableToOpenInfileException : public std::exception
		{
			virtual const char *what(void) const throw()
			{
				return ("Unable to open input file.");
			}
		};
		class	UnvalidDateException : public std::exception
		{
			virtual const char *what(void) const throw()
			{
				return ("Error: bad input");
			}
		};
		class	UnvalidArgException : public std::exception
		{
			virtual const char *what(void) const throw()
			{
				return ("Error: no rate found for this date.");
			}
		};
		class	NegativeValueException : public std::exception
		{
			virtual const char *what(void) const throw()
			{
				return ("Error: not a positive number.");
			}
		};
		class	ValueTooBigException : public std::exception
		{
			virtual const char *what(void) const throw()
			{
				return ("Error: too large a number.");
			}
		};
	private:
		BitcoinExchange(void);
		void	parseData(void);
		std::string						_fname;
		std::map<std::string, float>	_rates;
};

#endif