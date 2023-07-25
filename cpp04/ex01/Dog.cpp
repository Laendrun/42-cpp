/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:22:13 by saeby             #+#    #+#             */
/*   Updated: 2023/02/21 20:13:22 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog(void)
{
	std::cout << "Default Dog constructor called." << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
	return ;
}

Dog::Dog(Dog &d) : Animal(d._type)
{
	std::cout << "Dog copy constructor called." << std::endl;
	delete (this->_brain);
	this->_brain = new Brain(*(d._brain));
	return ;
}

Dog	&Dog::operator=(Dog const &d)
{
	this->_type = d._type;
	delete (this->_brain);
	this->_brain = new Brain(*(d._brain));
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called." << std::endl;
	delete (this->_brain);
}

void	Dog::makeSound(void) const
{
	std::cout << "Wouaf wouaf" << std::endl;
	return ;
}