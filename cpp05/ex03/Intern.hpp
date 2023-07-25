/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:00:13 by saeby             #+#    #+#             */
/*   Updated: 2023/03/01 13:32:38 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class	Intern
{
	public:
		Intern(void);
		Intern(const Intern &i);
		~Intern();
		Intern	&operator=(const Intern &i);

		AForm	*makeForm(std::string f_name, std::string f_target);

		class	FormNotFoundException : public std::exception
		{
			virtual const char	*what(void) const throw()
			{
				return ("Requested form not found.");
			}
		};
};

#endif