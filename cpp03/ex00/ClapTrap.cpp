/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:15:07 by saeby             #+#    #+#             */
/*   Updated: 2023/01/22 11:20:20 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

// Default constructor, everything is set by the callee
ClapTrap::ClapTrap(void) : _name("Default"), _hp(10), _ep(10), _ad(0)
{
	std::cout << "Default constructor called for ";
	std::cout << _GREEN << this->_name;
	std::cout << _RESET << std::endl;
	return ;
}

// Named constructor, other values are set by the callee
ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _ad(0)
{
	std::cout << "Named ClapTrap constructor called for ";
	std::cout << _GREEN << this->_name;
	std::cout << _RESET << std::endl;
	return ;
}

// Full constructor, everything is set by the caller
ClapTrap::ClapTrap(std::string name, uint hp, uint ep, uint ad) : _name(name), _hp(hp), _ep(ep), _ad(ad)
{
	std::cout << "Full ClapTrap Constructor called for ";
	std::cout << _GREEN << this->_name << _RESET;
	std::cout << " with " << _YELLOW << this->_hp << _RESET << " hp, ";
	std::cout << _YELLOW << this->_ep << _RESET << " ep, " << _YELLOW << this->_ad << _RESET << " ad.";
	std::cout << std::endl;
	return ;
}

// Copy constructor, everything is copied from the referenced ct ClapTrap
ClapTrap::ClapTrap(ClapTrap &ct) : _name(ct._name), _hp(ct._hp), _ep(ct._ep), _ad(ct._ad)
{
	std::cout << "ClapTrap copy constructor called for ";
	std::cout << _GREEN << this->_name << std::endl;
	std::cout << _RESET << std::endl;
	return ;
}

// Destructor
ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called for ";
	std::cout << _RED << this->_name;
	std::cout << _RESET << std::endl;
	return ;
}

// Assignement operator overload
ClapTrap &ClapTrap::operator=(const ClapTrap &ct) 
{
	this->_name = ct._name;
	this->_hp = ct._hp;
	this->_ep = ct._ep;
	this->_ad = ct._ad;
	return (*this);
}

// ++++++++++++++++++++++++++++++++++
// Member functions
// ++++++++++++++++++++++++++++++++++

void	ClapTrap::attack(const std::string &target)
{
	// ClapTrap <name> attacks <target>, causing <damage> points of damage
	if (this->_ep <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " tried to attack " << target << " but has no energy left." << std::endl;
		return ;
	}
	else if (this->_hp <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot attack as it has 0 hit points left." << std::endl;
		return ;
	}
	else
	{
		this->_ep--;
		std::cout << "ClapTrap " << _GREEN << this->_name << _RESET << " attacks " << _GREEN << target;
		std::cout << _RESET <<  ", causing " << _YELLOW << this->_ad << _RESET << " points of damage" << std::endl;
		return ;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp < amount)
	{
		std::cout << "ClapTrap " << _GREEN << this->_name << _RESET << " took " << _YELLOW;
		std::cout << amount << _RESET << " damage and passed away..." << std::endl;
	}
	else if (amount == 0)
	{
		std::cout << "Whoever tried to attack " << _GREEN << this->_name << _RESET << " is not really powerful and made ";
		std::cout << _YELLOW << amount << _RESET << " damage." << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _GREEN << this->_name << _RESET << " took " << _YELLOW << amount << _RESET;
		std::cout << " damage but survived since it had enough hit points left." << std::endl;
		this->_hp -= amount;
	}
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_ep <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " tried to repair itself but has no energy left." << std::endl;
		return ;
	}
	else if (this->_hp <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot repair itself as it has 0 hit points left." << std::endl;
		return ;
	}
	else
	{
		std::cout << "ClapTrap " << _GREEN << this->_name << _RESET << " repairs itself ";
		std::cout << _YELLOW << amount << _RESET << " hit points" << std::endl;
		this->_hp += amount;
		this->_ep--;
	}
	return ;
}

void	ClapTrap::status(void)
{
	std::cout << _GREEN << this->_name << _RESET << " status:" << std::endl;
	std::cout << "HP: " << _YELLOW << this->_hp << _RESET << std::endl;
	std::cout << "EP: " << _YELLOW << this->_ep << _RESET << std::endl;
	std::cout << "AD :" << _YELLOW << this->_ad << _RESET << std::endl;
	return ;
}

void	ClapTrap::setHp(uint amount)
{
	std::cout << _GREEN << this->_name << _RESET << " drank something weird and now has ";
	std::cout << _YELLOW << amount << _RESET << " hit points" << std::endl;
	this->_hp = amount;
	return ;
}

uint	ClapTrap::getHp(void)
{
	return (this->_hp);
}

void	ClapTrap::setAd(uint amount)
{
	std::cout << _GREEN << this->_name << _RESET << " drank something weird and now has ";
	std::cout << _YELLOW << amount << _RESET << " attack damage" << std::endl;
	this->_ad = amount;
	return ;
}

uint	ClapTrap::getAd(void)
{
	return (this->_ad);
}

void	ClapTrap::setEp(uint amount)
{
	std::cout << _GREEN << this->_name << _RESET << " drank something weird and now has ";
	std::cout << _YELLOW << amount << _RESET << " energy points" << std::endl;
	this->_ep = amount;
	return ;
}

uint	ClapTrap::getEp(void)
{
	return (this->_ep);
}