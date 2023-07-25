/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:41:16 by saeby             #+#    #+#             */
/*   Updated: 2023/02/21 20:05:01 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain constructor called." << std::endl;
	return ;
}

// Putting parentheses around the expression this->_ideas dereferences
// the pointer, thus creating a deep copy and not just passing the 
// same reference over to the new Brain

Brain::Brain(Brain &b)
{
	std::cout << "Brain copy constructor called." << std::endl;
	for (int i = 0; i < 100; i++)
		(this->_ideas)[i] = (b._ideas)[i];
	return ;
}

Brain	&Brain::operator=(const Brain &b)
{
	for (int i = 0; i < 100; i++)
		(this->_ideas)[i] = (b._ideas)[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called." << std::endl;
	return ;
}