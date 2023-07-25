/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:44:32 by saeby             #+#    #+#             */
/*   Updated: 2023/04/24 19:58:05 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(std::string dataFName) : _fname(dataFName)
{
	try
	{
		this->parseData();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		exit(1);
	}
}

// BitcoinExchange(const BitcoinExchange& be);
// BitcoinExchange	&operator=(const BitcoinExchange& be);

BitcoinExchange::BitcoinExchange(const BitcoinExchange& be)
{
	*this = be;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange& be)
{
	if (this != &be)
	{
		this->_fname = be.getFname();
		this->_rates = be.getRates();
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {}

void	BitcoinExchange::parseData(void)
{
	std::ifstream	data;
	std::string		line;

	data.open(this->_fname);
	if (!data.is_open())
		throw (BitcoinExchange::UnknownDataFileException());

	while (std::getline(data, line))
	{
		std::stringstream ss(line);
		std::string date;
		float rate;
		if (std::getline(ss, date, ',') && ss >> rate)
			this->_rates[date] = rate;
	}
}

float	BitcoinExchange::getRate(const std::string &d) const
{
	if (!this->validDate(d))
		throw (BitcoinExchange::UnvalidDateException());
	std::map<std::string, float>::const_iterator	it = this->_rates.find(d);
	if (it == this->_rates.end())
	{
		// exact date not found
		// found the first date that comes before

		// upper_bound returns an iterator to the first value above the given value
		// if not found, gives an iterator to the beginning of the map
		it = this->_rates.upper_bound(d);
		if (it == this->_rates.begin())
			throw (BitcoinExchange::UnvalidArgException());
		// decreasing the iterator by one since the iterator we got is one above what we are looking for
		--it;
	}
	// it->first returns the key
	// it->second returns the value => what we want
	return (it->second);
}

std::map<std::string, float>	BitcoinExchange::getRates(void) const
{
	return (this->_rates);
}

std::string	BitcoinExchange::getFname(void) const
{
	return (this->_fname);
}

bool	BitcoinExchange::validDate(std::string d) const
{

	int		year;
	int		month;
	int		day;
	char	sep;
	std::istringstream ss(d);
	ss >> year >> sep >> month >> sep >> day;
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (false);
	else if (month == 2)
	{
		if (year % 4 == 0)
		{
			if (day > 29)
				return (false);
		}
		else
			if (day > 28)
				return (false);
	}
	return (true);
}

bool	BitcoinExchange::validValue(float v) const
{
	if (v < 0)
		throw (BitcoinExchange::NegativeValueException());
	else if (v > 1000)
		throw (BitcoinExchange::ValueTooBigException());
	return (true);
}
