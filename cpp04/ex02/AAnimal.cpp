/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:37:12 by saeby             #+#    #+#             */
/*   Updated: 2023/02/22 08:41:45 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(void)
{
	std::cout << "Default Animal constructor called." << std::endl;
	this->_type = "Animal";
	return ;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "Typed Animal constructor called with type " << _YELLOW;
	std::cout << this->_type << _RESET << std::endl;
	return ;
}

AAnimal::AAnimal(AAnimal &a) : _type(a._type)
{
	std::cout << "Anmal copy constructor called." << std::endl;
	return ;
}

AAnimal	&AAnimal::operator=(const AAnimal &a)
{
	this->_type = a._type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "Animal destructor called." << std::endl;
	return ;
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}
