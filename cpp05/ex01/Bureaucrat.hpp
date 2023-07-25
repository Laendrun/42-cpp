/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:15:21 by saeby             #+#    #+#             */
/*   Updated: 2023/04/01 16:19:51 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "Form.hpp"

class	Form;

class	Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &b);
		~Bureaucrat();
		Bureaucrat	&operator=(const Bureaucrat &b);

		void		setGrade(int grade);
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		incrementGrade(void);
		void		decrementGrade(void);

		void		signForm(Form &f);

		class GradeTooHighException : public std::exception
		{
			virtual const char	*what(void) const throw()
			{
				return ("Bureaucrat grade can't be 0 or higher.");
			}
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char *what(void) const throw()
			{
				return ("Bureaucrat grand can't be 151 or lower.");
			}
		};

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b);

#endif