/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:03:39 by saeby             #+#    #+#             */
/*   Updated: 2023/01/22 11:19:03 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

// Default contructor, everything is set by the callee
FragTrap::FragTrap(void): ClapTrap("Default", 100, 100, 30)
{
	std::cout << "Default FragTrap constructor called for ";
	std::cout << _GREEN << this->_name;
	std::cout << _RESET << std::endl;
	return ;
}

// Named constructor, other values are set by the callee
FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "Named FragTrap constructor called for ";
	std::cout << _GREEN << this->_name;
	std::cout << _RESET << std::endl;
	return ;
}

// Full constructor, everything is set by the caller
FragTrap::FragTrap(std::string name, uint hp, uint ep, uint ad) : ClapTrap(name, hp, ep, ad)
{
	std::cout << "Full FragTrap constructor called for ";
	std::cout << _GREEN << this->_name << _RESET;
	std::cout << " with " << _YELLOW << this->_hp << _RESET << " hp, ";
	std::cout << _YELLOW << this->_ep << _RESET << " ep, " << _YELLOW << this->_ad << _RESET << " ad.";
	std::cout << std::endl;
	return ;
}

// Copy constructor, everything is copied from the referenced ft FragTrap
FragTrap::FragTrap(FragTrap &ft): ClapTrap()
{
	std::cout << "FragTrap copy constructor called for ";
	std::cout << _GREEN << this->_name << _RESET << std::endl;
	this->_name = ft._name;
	this->_hp = ft._hp;
	this->_ep = ft._ep;
	this->_ad = ft._ad;
	return ;
}

// Assignement operator overload
FragTrap &FragTrap::operator=(const FragTrap &ft)
{
	this->_name = ft._name;
	this->_hp = ft._hp;
	this->_ep = ft._ep;
	this->_ad = ft._ad;
	return (*this);
}

// Destructor
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called for ";
	std::cout << _RED << this->_name;
	std::cout << _RESET << std::endl;
	return ;
}

// ++++++++++++++++++++++++++++++++++
// Member functions
// ++++++++++++++++++++++++++++++++++

void	FragTrap::attack(const std::string &target)
{
	// ClapTrap <name> attacks <target>, causing <damage> points of damage
	if (this->_ep <= 0)
	{
		std::cout << "FragTrap " << this->_name << " tried to attack " << target << " but has no energy left." << std::endl;
		return ;
	}
	else if (this->_hp <= 0)
	{
		std::cout << "FragTrap " << this->_name << " cannot attack as it has 0 hit points left." << std::endl;
		return ;
	}
	else
	{
		this->_ep--;
		std::cout << "FragTrap " << _GREEN << this->_name << _RESET << " attacks " << _GREEN << target;
		std::cout << _RESET <<  ", causing " << _YELLOW << this->_ad << _RESET << " points of damage" << std::endl;
		return ;
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _GREEN << this->_name << _RESET << " puts his hand in the air and asks for a high five";
	std::cout << std::endl;
	return ;
}