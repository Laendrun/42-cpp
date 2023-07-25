/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:51:19 by saeby             #+#    #+#             */
/*   Updated: 2023/02/18 15:54:10 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void)
{
	std::cout << "Default WrongCat constructor called." << std::endl;
	this->_type = "WrongCat";
	return ;
}

WrongCat::WrongCat(WrongCat &c) : WrongAnimal(c._type)
{
	std::cout << "WrongCat copy constructor called.";
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called." << std::endl;
	return ;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat sound" << std::endl;
	return ;
}