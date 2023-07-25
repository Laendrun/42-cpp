/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:20:56 by saeby             #+#    #+#             */
/*   Updated: 2023/01/21 13:55:44 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// Constructors
/* This is the default constructor, it sets the required values
 * when it is called
 */
Fixed::Fixed(void) : _val(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int n)
{
	int	val = n;
	std::cout << "Int constructor called" << std::endl;
	for (int i = this->_bits; i > 0; i--)
		val *= 2;
	this->_val = val;
	return ;
}

Fixed::Fixed(const float f)
{
	float val = f;
	std::cout << "Float constructor called" << std::endl;
	for (int i = this->_bits; i > 0; i--)
		val *= 2;
	this->_val = roundf(val);
	return ;
}

// Copy constructor
/* Copy constructor are used to create a new element with 
 * the same values as the one passed as parameter
 */
Fixed::Fixed(const Fixed &t) : _val(t._val)
{
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

// Operator overload
/* an operator overload lets us define what happens (in this case) when
 * we write Fixed a = Fixed b for example
 * this could be done for += or -= or any other operator
 */
Fixed &Fixed::operator=(const Fixed &f) 
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_val = f._val;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const Fixed &f)
{
	o << f.toFloat();
	return (o);
}

// Destructor
/* This is the default constructor called when we don't the element anymore
 */ 
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_val);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_val = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
	float val = this->_val;
	for (int i = this->_bits; i > 0; i--)
		val /= 2;
	return (val);
}

int		Fixed::toInt(void) const
{
	int val = this->_val;
	for (int i = this->_bits; i > 0; i--)
		val /= 2;
	return (val);
}
