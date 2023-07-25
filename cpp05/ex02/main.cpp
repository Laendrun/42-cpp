/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:14:32 by saeby             #+#    #+#             */
/*   Updated: 2023/04/01 16:36:52 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::cout << std::cout << "\e[1;1H\e[2J";
	try
	{
		Bureaucrat	*b = new Bureaucrat("Bob", 30);
		Bureaucrat	*b1 = new Bureaucrat("Marley", 10);
		ShrubberyCreationForm	*scf = new ShrubberyCreationForm();
		RobotomyRequestForm		*rrf = new RobotomyRequestForm();
		PresidentialPardonForm	*ppf = new PresidentialPardonForm();
		b->signForm(*scf);
		b->signForm(*rrf);
		b1->signForm(*ppf);
		b->executeForm(*rrf);
		b->executeForm(*scf);
		b1->executeForm(*ppf);
		delete(b);
		delete(scf);
		delete(rrf);
		delete(ppf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}