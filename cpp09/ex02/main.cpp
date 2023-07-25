/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:50:39 by saeby             #+#    #+#             */
/*   Updated: 2023/05/01 11:41:07 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
		return (1);

	PmergeMe	pm;

	try
	{
		std::vector<int> a = pm.parseAsVec(ac, av);
		std::list<int> b = pm.parseAsList(ac, av);
		// pm.checkInput(a);
		// pm.checkInput(b);

		std::cout << "Before: ";
		for (unsigned int i = 0; i < a.size(); i++)
			std::cout << a[i] << ' ';
		std::cout << std::endl;

		double	tBegVec = pm.getTime();
		a = pm.fjmi(a);
		double	deltaTVec = pm.getDelta(tBegVec);
		double	tBegList = pm.getTime();
		pm.fjmi(b);
		double	deltaTList = pm.getDelta(tBegList);

		std::cout << "After: ";
		for (unsigned int i = 0; i < a.size(); i++)
			std::cout << a[i] << ' ';
		std::cout << std::endl;

		std::cout << "Time to process " << ac - 1 << " elements with std::vector : " << std::setprecision(5) << deltaTVec << " us" << std::endl;
		std::cout << "Time to process " << ac - 1 << " elements with std::list : " << std::setprecision(5) << deltaTList << " us" << std::endl;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << std::endl;
		std::cout << e.what() << std::endl; // asked in the subject to print error messages to standard output
	}

	return (0);
}