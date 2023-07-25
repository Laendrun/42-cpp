/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:20:46 by saeby             #+#    #+#             */
/*   Updated: 2023/02/22 10:41:26 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(void)
{
	return ;
}

AMateria::AMateria(const std::string &type)
{
	this->_type = type;
	return ;
}

AMateria::AMateria(const AMateria &m)
{
	this->_type = m._type;
	return ;
}

AMateria::~AMateria()
{
	return ;
}

AMateria	&AMateria::operator=(const AMateria &m)
{
	this->_type = m._type;
	return (*this);
}

const std::string	&AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "* Random Fortnite dance on " << target.getName() << std::endl;
	return ;
}