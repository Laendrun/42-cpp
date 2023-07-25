/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:46:53 by saeby             #+#    #+#             */
/*   Updated: 2023/02/17 21:53:11 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point	p(1.5f, 1);
	Point	a(0, 0);
	Point	b(4, 4);
	Point	c(8, 0);

	std::cout << bsp(a, b, c, p) << std::endl;
	return (0);
}
