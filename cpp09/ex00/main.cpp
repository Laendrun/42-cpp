/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:46:32 by saeby             #+#    #+#             */
/*   Updated: 2023/04/20 14:44:37 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Bitcoin Exchange
// container => map
// map<std::string(date), float(value)>

// https://stackoverflow.com/questions/216823/how-to-trim-an-stdstring

#include <iostream>
#include <fstream>
#include <map>
#include "BitcoinExchange.hpp"

int	putError(std::string s)
{
	std::cerr << s << std::endl;
	return (1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (putError("Wrong number of arguments."));

	try
	{
		std::ifstream	infile;
		std::string		line;

		BitcoinExchange e("data.csv");
		infile.open(av[1]);
		if (!infile.is_open())
			throw (BitcoinExchange::UnableToOpenInfileException());
		while (std::getline(infile, line))
		{
			std::stringstream ss(line);
			std::string date;
			float value;
			if (std::getline(ss, date, '|') && ss >> value)
			{
				try
				{
					date.erase(date.find_last_not_of(" \n\r\t")+1);
					if (e.validValue(value))
					{
						float rate = e.getRate(date);
						float result = rate * value;
						std::cout << date << " => " << value << " = " << result << std::endl;
					}
				}
				catch (std::exception &e)
				{
					std::cerr << e.what() << std::endl;
				}
			}
			else
				std::cerr << "Error: bad input => " << line << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}