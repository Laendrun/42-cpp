/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:25:34 by saeby             #+#    #+#             */
/*   Updated: 2023/04/01 14:12:53 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
{
	std::cout << "Default Cat constructor called." << std::endl;
	this->_type = "Cat";
	return ;
}

Cat::Cat(Cat &c) : Animal(c._type)
{
	std::cout << "Cat copy constructor called.";
	return ;
}

Cat	&Cat::operator=(Cat const &c)
{
	std::cout << "Cat copy constructor called." << std::endl;
	this->_type = c._type;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called." << std::endl;
	return ;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meeeooooowwww" << std::endl;
	return ;
}
