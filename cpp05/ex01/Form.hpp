/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:36:02 by saeby             #+#    #+#             */
/*   Updated: 2023/04/01 15:08:47 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	public:
		Form(void);
		Form(std::string name);
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form &f);
		~Form();
		Form	&operator=(const Form &f);

		std::string	getName(void) const;
		int			getSignGrade(void) const;
		int			getExecGrade(void) const;
		bool		isSigned(void) const;

		void		beSigned(Bureaucrat &b);

		class	GradeTooLowException : public std::exception
		{
			virtual const char	*what(void) const throw()
			{
				return ("Form grade can't be 151 or lower OR Bureaucrat grade too low to sign form.");
			}
		};
		class	GradeTooHighException : public std::exception
		{
			virtual const char	*what(void) const throw()
			{
				return ("Form grade can't be 0 or higher.");
			}
		};

	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
};

std::ostream &operator<<(std::ostream &o, const Form &b);

#endif