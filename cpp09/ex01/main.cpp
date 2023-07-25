/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:47:17 by saeby             #+#    #+#             */
/*   Updated: 2023/04/24 21:04:58 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

// RPN
// container => stack

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		std::cerr << "Usage: " << av[0] << " <RPN expression>" << std::endl;
		return (1);
	}
	try
	{
		RPN	rpn;
		rpn.rpn(av[1]);
		std::cout << "Result: " << rpn.getResult() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}