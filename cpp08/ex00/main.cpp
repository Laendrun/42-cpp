/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:08:30 by saeby             #+#    #+#             */
/*   Updated: 2023/04/13 11:21:27 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.tpp"

int	main(void)
{
	int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	std::vector<int>	vect(arr, arr + sizeof(arr)/sizeof(arr[0]));
	std::list<int>		list(arr, arr + sizeof(arr)/sizeof(arr[0]));

	test("Vector", vect, 5);
	test("List", list, 3);
	test("List", list, 53);
	test("Vector", vect, 42);
	return (0);
}