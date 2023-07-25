/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:05:32 by saeby             #+#    #+#             */
/*   Updated: 2023/04/01 18:52:48 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("Default form"), _signed(false), _signGrade(100), _execGrade(75)
{
	return ;
}

Form::Form(std::string name) : _name(name), _signed(false), _signGrade(100), _execGrade(75)
{
	return ;
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw (AForm::GradeTooHighException());
	if (this->_signGrade > 150 || this->_execGrade > 150)
		throw (AForm::GradeTooLowException());
	return ;
}

Form::Form(const Form &f) : _name(f.getName()), _signed(f.isSigned()), _signGrade(f.getSignGrade()), _execGrade(f.getExecGrade())
{
	return ;
}

Form::~Form()
{
	return ;
}

Form	&Form::operator=(const Form &f)
{
	this->_signed = f.isSigned();
	return (*this);
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

int	Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	Form::getExecGrade(void) const
{
	return (this->_execGrade);
}

bool	Form::isSigned(void) const
{
	return (this->_signed);
}

void	Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw (Form::GradeTooLowException());
	return ;
}

std::ostream &operator<<(std::ostream &o, const Form &f)
{
	std::string	isSigned = f.isSigned() ? "true" : "false";
	o << "Form " << f.getName() << ", signed: " << isSigned << ", SignGrade: ";
	o << f.getSignGrade() << ", ExecGrade: " << f.getExecGrade() << ".";
	return (o);
}
