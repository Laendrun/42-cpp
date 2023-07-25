/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:05:32 by saeby             #+#    #+#             */
/*   Updated: 2023/04/01 18:52:32 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("Default AForm"), _signed(false), _signGrade(100), _execGrade(75)
{
	return ;
}

AForm::AForm(std::string name) : _name(name), _signed(false), _signGrade(100), _execGrade(75)
{
	return ;
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw (AForm::GradeTooHighException());
	if (this->_signGrade > 150 || this->_execGrade > 150)
		throw (AForm::GradeTooLowException());
	return ;
}

AForm::AForm(const AForm &f) : _name(f.getName()), _signed(false), _signGrade(f.getSignGrade()), _execGrade(f.getExecGrade())
{
	return ;
}

AForm::~AForm()
{
	return ;
}

AForm	&AForm::operator=(const AForm &f)
{
	this->_signed = f.isSigned();
	return (*this);
}

void	AForm::setSigned(bool sign)
{
	this->_signed = sign;
	return ;
}

void	AForm::setTarget(std::string target)
{
	this->_target = target;
	return ;
}

std::string	AForm::getTarget(void) const
{
	return (this->_target);
}

std::string	AForm::getName(void) const
{
	return (this->_name);
}

int	AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	AForm::getExecGrade(void) const
{
	return (this->_execGrade);
}

bool	AForm::isSigned(void) const
{
	return (this->_signed);
}

void	AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw (AForm::GradeTooLowException());
	return ;
}

std::ostream &operator<<(std::ostream &o, const AForm &f)
{
	o << "AForm " << f.getName() << ", signed: " << f.isSigned() << ", SignGrade: ";
	o << f.getSignGrade() << ", ExecGrade: " << f.getExecGrade() << ".";
	return (o);
}
