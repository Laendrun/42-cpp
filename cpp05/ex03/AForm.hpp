/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:36:02 by saeby             #+#    #+#             */
/*   Updated: 2023/04/01 16:39:51 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	public:
		AForm(void);
		AForm(std::string name);
		AForm(std::string name, int signGrade, int execGrade);
		AForm(const AForm &f);
		virtual ~AForm();
		AForm	&operator=(const AForm &f);

		void			setSigned(bool sign);
		void			setTarget(std::string target);
		std::string		getTarget(void) const;
		std::string		getName(void) const;
		int				getSignGrade(void) const;
		int				getExecGrade(void) const;
		bool			isSigned(void) const;

		void			beSigned(Bureaucrat &b);
		virtual void	execute(Bureaucrat const &executor) = 0;

		class	GradeTooLowException : public std::exception
		{
			virtual const char	*what(void) const throw()
			{
				return ("Form grade can't be 151 or lower \nOR Bureaucrat grade too low to sign form\nOR Bureaucrat grade too low to exec form.");
			}
		};
		class	GradeTooHighException : public std::exception
		{
			virtual const char	*what(void) const throw()
			{
				return ("Form grade can't be 0 or higher.");
			}
		};
		class	FormNotSignedException : public std::exception
		{
			virtual const char	*what(void) const throw()
			{
				return ("Form not signed.");
			}
		};

	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
		std::string			_target;
};

std::ostream &operator<<(std::ostream &o, const AForm &b);

#endif