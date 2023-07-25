/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:35:34 by saeby             #+#    #+#             */
/*   Updated: 2023/02/18 17:41:23 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"
#include <iostream>

WrongDog::WrongDog(void)
{
	std::cout << "Default WrongDog constructor called." << std::endl;
	this->_type = "WrongDog";
	return ;
}

WrongDog::WrongDog(WrongDog &d) : WrongAnimal(d._type)
{
	std::cout << "WrongDog copy constructor called.";
	return ;
}

WrongDog::~WrongDog(void)
{
	std::cout << "WrongDog destructor called." << std::endl;
	return ;
}

void	WrongDog::makeSound(void) const
{
	std::cout << "WrongDog sound" << std::endl;
	return ;
}