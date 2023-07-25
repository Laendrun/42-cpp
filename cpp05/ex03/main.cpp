/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:14:32 by saeby             #+#    #+#             */
/*   Updated: 2023/04/01 16:45:33 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::cout << std::cout << "\e[1;1H\e[2J";
	try
	{
		Bureaucrat	boss = Bureaucrat("Boss", 1);
		Bureaucrat	babyboss = Bureaucrat("Babyboss", 10);
		Intern		youThere;
		AForm		*rrf;

		rrf = youThere.makeForm("robotomy request", "Bender");
		// AForm *wf;
		// wf = youThere.makeForm("random request", "Bender");

		babyboss.signForm(*rrf);
		boss.executeForm(*rrf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}