/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:56:48 by saeby             #+#    #+#             */
/*   Updated: 2023/03/01 12:56:51 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>

class	PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &ppf);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &ppf);

		void	execute(Bureaucrat const &executor);
};

#endif