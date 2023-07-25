/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:05:35 by saeby             #+#    #+#             */
/*   Updated: 2023/04/15 18:30:01 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
# define _RESET "\e[0m"
# define _RED "\e[31m"
# define _GREEN "\e[32m"
# define _YELLOW "\e[33m"
# define _CYAN "\e[36m"

void	print(int n)
{
	std::cout << n << " ";
}

void	test(int size, int range)
{
	std::cout << "==================================" << std::endl;
	std::cout << "Testing with " << size << " values." << std::endl;

	Span				s(size);
	std::vector<int>	values;
	for (int i = 0; i < size; i++)
		values.push_back(rand() % (2 * range) - range);
	s.addNumber(values.begin(), values.end());
	std::cout << "Values :" << std::endl;
	std::cout << _YELLOW << "[";
	std::for_each(values.begin(), values.end(), print);
	std::cout << "]" << _RESET << std::endl;
	std::cout << _GREEN << "Shortest: " << s.shortestSpan() << std::endl;
	std::cout << "Longest: " << s.longestSpan() << _RESET << std::endl;
	std::cout << "==================================" << std::endl;
}

int main()
{
	srand(time(NULL));
	try
	{
		test(2, 100);
		test(3, 10);
		test(3, 50);
		test(3, 100);
		test(5, 10);
		test(10, 50);
		test(10000, 10000);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}