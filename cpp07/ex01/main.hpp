/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:29:05 by saeby             #+#    #+#             */
/*   Updated: 2023/04/03 21:13:01 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP
# include <iostream>

// https://www.geeksforgeeks.org/templates-cpp/

template <typename T> void iter(T* arr, int s, void (&f)(T &))
{
	for (int i = 0; i < s; i++)
		f(arr[i]);
}

template <typename T> void test(std::string n, T* a, int s, void (&f)(T &))
{
	std::cout << "Test " << n << std::endl;
	std::cout << "Array before iter:" << std::endl;
	for (int i = 0; i < s; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
	std::cout << "Running iter template..." << std::endl;
	::iter(a, s, f);
	std::cout << "Array after iter:" << std::endl;
	for (int i = 0; i < s; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}

#endif