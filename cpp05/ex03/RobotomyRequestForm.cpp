/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:28:27 by saeby             #+#    #+#             */
/*   Updated: 2023/04/01 16:43:29 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <stdlib.h>
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request Form", 72, 45)
{
	this->setTarget("RRF_Target");
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45)
{
	this->setTarget(target);
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rrf) : AForm(rrf.getName(), rrf.getSignGrade(), rrf.getExecGrade())
{
	this->setTarget(rrf.getTarget());
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rrf)
{
	this->setSigned(rrf.isSigned());
	this->setTarget(rrf.getTarget());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor)
{
	if (!this->isSigned())
		throw (AForm::FormNotSignedException());
	if (executor.getGrade() > this->getExecGrade())
		throw (AForm::GradeTooLowException());
	
	srand(time(NULL));
	std::cout << "making weird drilling noises..." << std::endl;
	if (rand() % 2)
		std::cout << this->getTarget() << " robotomized." << std::endl;
	else
		std::cout << "robotomization failed for " << this->getTarget() << std::endl;
	return ;
}
