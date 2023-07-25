/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 09:48:50 by saeby             #+#    #+#             */
/*   Updated: 2023/01/22 10:25:27 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

// Default constructor, everything is set by the callee
ScavTrap::ScavTrap(void) : ClapTrap("Default", 100, 50, 20)
{
	std::cout << "Default ScavTrap constructor called for ";
	std::cout << _GREEN << this->_name;
	std::cout << _RESET << std::endl;
	return ;
}

// Name constructor, other values are set by the callee
ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "Named ScavTrap constructor called for ";
	std::cout << _GREEN << this->_name;
	std::cout << _RESET << std::endl;
	return ;
}

// Full constructor, everything is set by the caler
ScavTrap::ScavTrap(std::string name, uint hp, uint ep, uint ad) : ClapTrap(name, hp, ep, ad)
{
	std::cout << "Full ScavTrap Constructor called for ";
	std::cout << _GREEN << this->_name << _RESET;
	std::cout << " with " << _YELLOW << this->_hp << _RESET << " hp, ";
	std::cout << _YELLOW << this->_ep << _RESET << " ep, " << _YELLOW << this->_ad << _RESET << " ad.";
	std::cout << std::endl;
	return ;
}

// Copy constructor, everything is copied from the referenced st ScavTrap
ScavTrap::ScavTrap(ScavTrap &st) : ClapTrap()
{
	std::cout << "ScavTrap copy constructor called for ";
	std::cout << _GREEN << this->_name << std::endl;
	std::cout << _RESET << std::endl;
	this->_name = st._name;
	this->_hp = st._hp;
	this->_ep = st._ep;
	this->_ad = st._ad;
	return ;
}

// Destructor
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called for ";
	std::cout << _RED << this->_name;
	std::cout << _RESET << std::endl;
	return ;
}

// Assignement operator overload
ScavTrap &ScavTrap::operator=(const ScavTrap &st)
{
	this->_name = st._name;
	this->_hp = st._hp;
	this->_ep = st._ep;
	this->_ad = st._ad;
	return (*this);
}

// ++++++++++++++++++++++++++++++++++
// Member functions
// ++++++++++++++++++++++++++++++++++

void	ScavTrap::attack(const std::string &target)
{
	// ClapTrap <name> attacks <target>, causing <damage> points of damage
	if (this->_ep <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " tried to attack " << target << " but has no energy left." << std::endl;
		return ;
	}
	else if (this->_hp <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot attack as it has 0 hit points left." << std::endl;
		return ;
	}
	else
	{
		this->_ep--;
		std::cout << "ScavTrap " << _GREEN << this->_name << _RESET << " attacks " << _GREEN << target;
		std::cout << _RESET <<  ", causing " << _YELLOW << this->_ad << _RESET << " points of damage" << std::endl;
		return ;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _GREEN << this->_name << _RESET << " has entered";
	std::cout << _YELLOW << " Gate Keeper " << _RESET << "mode" << std::endl;
	return ; 
}
