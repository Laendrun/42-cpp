/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:50:24 by saeby             #+#    #+#             */
/*   Updated: 2023/01/22 14:18:44 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void)
{
	std::cout << "Default DiamondTrap constructor called for ";
	std::cout << _GREEN << this->_name;
	std::cout << _RESET << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << "Named DiamondTrap constructor called for ";
	std::cout << _GREEN << this->_name;
	std::cout << _RESET << std::endl;
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->FragTrap::_hp = 100;
	this->ScavTrap::_ep = 50;
	this->FragTrap::_ad = 30;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap &dt)
{
	this->_name = dt._name;
	this->ClapTrap::_name = dt.ClapTrap::_name;
	this->FragTrap::_hp = dt.FragTrap::_hp;
	this->ScavTrap::_ep = dt.ScavTrap::_ep;
	this->FragTrap::_ad = dt.FragTrap::_ad;
	return ;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &dt)
{
	this->_name = dt._name;
	this->ClapTrap::_name = dt.ClapTrap::_name;
	this->FragTrap::_hp = dt.FragTrap::_hp;
	this->ScavTrap::_ep = dt.ScavTrap::_ep;
	this->FragTrap::_ad = dt.FragTrap::_ad;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called for ";
	std::cout << _RED << this->_name;
	std::cout << _RESET << std::endl;
	return ;
}

// ++++++++++++++++++++++++++++++++++
// Member functions
// ++++++++++++++++++++++++++++++++++

void	DiamondTrap::attack(const std::string &target)
{
	this->ScavTrap::attack(target);
	return ;
}

void	DiamondTrap::whoami(void)
{
	std::cout << "DiamondTrap name: " << _GREEN << this->_name << _RESET;
	std::cout << " Base ClapTrap name: " << _GREEN << this->ClapTrap::_name << _RESET << std::endl;
	return ;
}
