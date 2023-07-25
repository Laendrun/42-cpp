/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:54:08 by saeby             #+#    #+#             */
/*   Updated: 2023/02/17 21:06:12 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// Constructor function
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

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
