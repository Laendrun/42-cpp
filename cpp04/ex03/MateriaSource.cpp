/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:32:56 by saeby             #+#    #+#             */
/*   Updated: 2023/02/22 18:06:40 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		(this->_templates)[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(const MateriaSource &ms) : IMateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (!(ms._templates)[i])
			(this->_templates)[i] = NULL;
		else
			(this->_templates)[i] = (ms._templates)[i]->clone();
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &ms)
{
	for (int i = 0; i < 4; i++)
	{
		if ((this->_templates)[i])
			delete ((this->_templates)[i]);
		if (!(ms._templates)[i])
			(this->_templates)[i] = NULL;
		else
			(this->_templates)[i] = (ms._templates)[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	return ;
}

void	MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!(this->_templates)[i])
		{
			// std::cout << "* learning new ability " << m->getType() << " *" << std::endl;
			(this->_templates)[i] = m;
			break ;
		}
	}
	return ;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if ((this->_templates)[i]->getType() == type)
			return ((this->_templates)[i]->clone());
	}
	return (0);
}
