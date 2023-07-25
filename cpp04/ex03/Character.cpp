/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:55:58 by saeby             #+#    #+#             */
/*   Updated: 2023/02/22 18:06:30 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(void)
{
	this->_name = "Name";
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	return ;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	return ;
}

Character::Character(const Character &c)
{
	for (int i = 0; i < 4; i++)
	{
		if (!(c._inventory)[i])
			(this->_inventory)[i] = NULL;
		else
			(this->_inventory)[i] = (c._inventory)[i]->clone();
	}
	this->_name = c._name;
	return ;
}

Character	&Character::operator=(const Character &c)
{
	for (int i = 0; i < 4; i++)
	{
		if ((this->_inventory)[i])
			delete ((this->_inventory)[i]);
		if (!(c._inventory)[i])
			(this->_inventory)[i] = NULL;
		else
			(this->_inventory)[i] = (c._inventory)[i]->clone();
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if ((this->_inventory)[i])
			delete ((this->_inventory)[i]);
	}
	return ;
}

std::string const	&Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!(this->_inventory)[i])
		{
			// std::cout << "* Equipping " << m->getType() << " into slot " << i << " *" <<std::endl;
			(this->_inventory)[i] = m;
			break ;
		}
	}
	return ;
}

void	Character::unequip(int idx)
{
	if ((this->_inventory)[idx])
	{
		// std::cout << "* dropping " << (this->_inventory)[idx]->getType() << " on the ground *" << std::endl;
		(this->_inventory)[idx] = NULL;
	}
	return ;
}

void	Character::use(int idx, ICharacter &target)
{
	if ((this->_inventory)[idx])
	{
		(this->_inventory)[idx]->use(target);
	}
	return ;
}
