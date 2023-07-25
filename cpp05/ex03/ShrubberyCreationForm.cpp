/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:13:12 by saeby             #+#    #+#             */
/*   Updated: 2023/04/01 16:44:11 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation Form", 145, 137)
{
	this->setTarget("SCF_Target");
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137)
{
	this->setTarget(target);
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scf) : AForm(scf.getName(), scf.getSignGrade(), scf.getExecGrade())
{
	this->setTarget(scf.getTarget());
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &scf)
{
	this->setSigned(scf.isSigned());
	this->setTarget(scf.getTarget());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return ;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
	if (!this->isSigned())
		throw (AForm::FormNotSignedException());
	if (executor.getGrade() > this->getExecGrade())
		throw (AForm::GradeTooLowException());
	std::string	fn = this->getTarget() + "_shrubbery";
	std::ofstream outfile (fn);
	outfile << TREE << std::endl;
	outfile.close();
	return ;
}