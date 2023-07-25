/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:04:13 by saeby             #+#    #+#             */
/*   Updated: 2023/03/01 13:40:39 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

typedef struct	list
{
	std::string	name;
	AForm	*form;
}	t_list;


Intern::Intern(void)
{
	return ;
}

Intern::Intern(const Intern &i)
{
	(void) i;
	return ;
}

Intern::~Intern()
{
	return ;
}

Intern	&Intern::operator=(const Intern &i)
{
	(void) i;
	return (*this);
}

AForm	*Intern::makeForm(std::string f_name, std::string f_target)
{
	AForm	*newF = NULL;
	t_list	list[3] =
	{
		{"robotomy request", new RobotomyRequestForm(f_target)},
		{"presidential pardon", new PresidentialPardonForm(f_target)},
		{"shrubbery creation", new ShrubberyCreationForm(f_target)}
	};
	for (int i = 0; i < 3; i++)
	{
		if (list[i].name == f_name)
			newF = list[i].form;
		else
			delete (list[i].form);
	}
	if (!newF)
		throw(FormNotFoundException());
	std::cout << "Intern creates " << newF->getName() << std::endl;
	return (newF);
}