/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:03:14 by saeby             #+#    #+#             */
/*   Updated: 2023/02/23 17:32:34 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>

# define TREE "        _-_\n     /~~   ~~\\\n  /~~         ~~\\\n {               }\n  \\  _-     -_  /\n    ~  \\\\ //  ~\n _- -   | | _- _\n   _ -  | |   -_\n       // \\\\"

class	ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &scf);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &scf);

		void	execute(Bureaucrat const &executor);
};

#endif