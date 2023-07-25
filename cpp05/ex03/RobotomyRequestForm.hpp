/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:11:59 by saeby             #+#    #+#             */
/*   Updated: 2023/02/23 18:49:50 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>

class	RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &rrf);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &rrf);

		void	execute(Bureaucrat const &executor);
};

#endif