/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:25:34 by saeby             #+#    #+#             */
/*   Updated: 2023/02/21 20:13:29 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat(void)
{
	std::cout << "Default Cat constructor called." << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
	return ;
}

Cat::Cat(Cat &c) : Animal(c._type)
{
	std::cout << "Cat copy constructor called.";
	delete (this->_brain);
	this->_brain = new Brain(*(c._brain));
	return ;
}

Cat	&Cat::operator=(Cat const &c)
{
	this->_type = c._type;
	delete (this->_brain);
	this->_brain = new Brain(*(c._brain));
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called." << std::endl;
	delete (this->_brain);
	return ;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meeeooooowwww" << std::endl;
	return ;
}
