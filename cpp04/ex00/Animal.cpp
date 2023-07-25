/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:37:12 by saeby             #+#    #+#             */
/*   Updated: 2023/02/18 15:57:18 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(void)
{
	std::cout << "Default Animal constructor called." << std::endl;
	this->_type = "Animal";
	return ;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Typed Animal constructor called with type " << _YELLOW;
	std::cout << this->_type << _RESET << std::endl;
	return ;
}

Animal::Animal(Animal &a) : _type(a._type)
{
	std::cout << "Animal copy constructor called." << std::endl;
	return ;
}

Animal	&Animal::operator=(const Animal &a)
{
	this->_type = a._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called." << std::endl;
	return ;
}

void	Animal::makeSound(void) const
{
	std::cout << "Unknown sound (default Animal or no type)" << std::endl;
	return ;
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}
