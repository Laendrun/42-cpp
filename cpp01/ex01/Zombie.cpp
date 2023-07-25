/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:54:08 by saeby             #+#    #+#             */
/*   Updated: 2023/02/17 20:02:51 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// Constructors
Zombie::Zombie(void)
{
	std::cout << "Default Zombie Constructor called" << std::endl;
	return ;
}

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << "Zombie \"" << this->name << "\" Constructor called" << std::endl;
	return ;
}

// Destructor
Zombie::~Zombie(void)
{
	std::cout << "Zombie \"" << this->name << "\" Destructor called" << std::endl;
	return ;
}

// Member functions

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
	return ;
}
