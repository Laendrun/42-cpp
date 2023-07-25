/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:36:47 by saeby             #+#    #+#             */
/*   Updated: 2023/02/18 15:57:14 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void)
{
	std::cout << "Default WrongAnimal constructor called." << std::endl;
	this->_type = "WrongAnimal";
	return ;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "Typed WrongAnimal constructor called with type " << _YELLOW;
	std::cout << this->_type << _RESET << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal &a) : _type(a._type)
{
	std::cout << "WrongAnimal copy constructor called." << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called." << std::endl;
	return ;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &a)
{
	this->_type = a._type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal sound" << std::endl;
	return ;
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}
