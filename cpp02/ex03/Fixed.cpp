/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:20:56 by saeby             #+#    #+#             */
/*   Updated: 2023/01/21 15:46:14 by saeby            ###   ########.fr       */
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
	return ;
}

Fixed::Fixed(const int n)
{
	int	val = n;
	for (int i = this->_bits; i > 0; i--)
		val *= 2;
	this->_val = val;
	return ;
}

Fixed::Fixed(const float f)
{
	float val = f;
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
	return ;
}

// Destructor
/* This is the default constructor called when we don't the element anymore
 */ 
Fixed::~Fixed(void)
{
	return ;
}

// Assignment operator overload
Fixed &Fixed::operator=(const Fixed &f) 
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_val = f._val;
	return (*this);
}

// Comparison operators overload
bool	Fixed::operator>(const Fixed &f) const
{
	return (this->toFloat() > f.toFloat());
}

bool	Fixed::operator<(const Fixed &f) const
{
	return (this->toFloat() < f.toFloat());
}

bool	Fixed::operator>=(const Fixed &f) const
{
	return (this->toFloat() >= f.toFloat());
}

bool	Fixed::operator<=(const Fixed &f) const
{
	return (this->toFloat() <= f.toFloat());
}

bool	Fixed::operator==(const Fixed &f) const
{
	return (this->toFloat() == f.toFloat());
}

bool	Fixed::operator!=(const Fixed &f) const
{
	return (this->toFloat() != f.toFloat());
}

// Arithmethic operators overload
Fixed	Fixed::operator+(const Fixed &f) const
{
	return (Fixed(this->toFloat() + f.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &f) const
{
	return (Fixed(this->toFloat() - f.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &f) const
{
	return (Fixed(this->toFloat() * f.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &f) const
{
	return (Fixed(this->toFloat() / f.toFloat()));
}

// Increment and decrement operators overload
Fixed	&Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	val = (*this);
	this->setRawBits(this->getRawBits() + 1);
	return (val);
}

Fixed	&Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	val = (*this);
	this->setRawBits(this->getRawBits() + 1);
	return (val);
}

std::ostream &operator<<(std::ostream &o, const Fixed &f)
{
	o << f.toFloat();
	return (o);
}

Fixed	&Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed	&Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed	&Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed	&Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

int	Fixed::getRawBits(void) const
{
	return (this->_val);
}

void	Fixed::setRawBits(int const raw)
{
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
