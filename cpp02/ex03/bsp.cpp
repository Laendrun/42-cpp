/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:53:19 by saeby             #+#    #+#             */
/*   Updated: 2023/02/17 21:53:00 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

// https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle#:~:text=A%20simple%20way%20is%20to,point%20is%20inside%20the%20triangle.

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool	d1, d2, d3;
	
	d1 = Point::sign(a, point, a, b);
	d2 = Point::sign(b, point, b, c);
	d3 = Point::sign(c, point, c, a);

	return (d1 == d2 && d2 == d3);
}
