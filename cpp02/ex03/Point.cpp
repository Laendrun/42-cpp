/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:59:31 by saeby             #+#    #+#             */
/*   Updated: 2023/02/17 21:53:21 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

// Constructors
Point::Point(void) : _x(Fixed(0)), _y(Fixed(0))
{
	return ;
}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y)
{
	return ;
}

Point::Point(const Point &p) : _x(p._x), _y(p._y)
{
	return ;
}

// Destructor

Point::~Point(void)
{
	return ;
}

// Assignment operator overload

Point &Point::operator=(const Point &p)
{
	this->_x = p._x;
	this->_y = p._y;
	return (*this);
}

bool	Point::sign(const Point &a, const Point &b, const Point &c, const Point &d)
{
	Fixed	result;

	result = (b._x - a._x) * (d._y - c._y) - (d._x - c._x) * (b._y - a._y);
	return (result > 0);
}
