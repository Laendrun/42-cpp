/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:20:56 by saeby             #+#    #+#             */
/*   Updated: 2023/01/21 11:45:11 by saeby            ###   ########.fr       */
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
