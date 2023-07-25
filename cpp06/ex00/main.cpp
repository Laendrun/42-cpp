/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:55:27 by saeby             #+#    #+#             */
/*   Updated: 2023/04/01 22:45:46 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int	puterr(std::string m1, std::string m2)
{
	std::cerr << m1 << std::endl;
	std::cerr << m2 << std::endl;
	return (1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (puterr("Wrong number of arguments, expected 1.", "./convert [(char)(int)(double)(float)]"));

	try
	{
		ScalarConverter::convert(av[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}