/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:22:13 by saeby             #+#    #+#             */
/*   Updated: 2023/04/01 14:13:13 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
{
	std::cout << "Default Dog constructor called." << std::endl;
	this->_type = "Dog";
	return ;
}

Dog::Dog(Dog &d) : Animal(d._type)
{
	std::cout << "Dog copy constructor called." << std::endl;
	return ;
}

Dog	&Dog::operator=(Dog const &d)
{
	std::cout << "Dog copy constructor called." << std::endl;
	this->_type = d._type;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called." << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Wouaf wouaf" << std::endl;
	return ;
}