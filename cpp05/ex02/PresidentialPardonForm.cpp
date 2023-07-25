/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:59:29 by saeby             #+#    #+#             */
/*   Updated: 2023/04/01 16:36:28 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Pardon Form", 25, 5)
{
	this->setTarget("PPF_Target");
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5)
{
	this->setTarget(target);
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ppf) : AForm(ppf.getName(), ppf.getSignGrade(), ppf.getExecGrade())
{
	this->setTarget(ppf.getTarget());
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &ppf)
{
	this->setSigned(ppf.isSigned());
	this->setTarget(ppf.getTarget());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return ;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor)
{
	if (!this->isSigned())
		throw (AForm::FormNotSignedException());
	if (executor.getGrade() > this->getExecGrade())
		throw (AForm::GradeTooLowException());
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblerox." << std::endl;
	return ;
}