/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:14:32 by saeby             #+#    #+#             */
/*   Updated: 2023/02/22 20:37:58 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << std::cout << "\e[1;1H\e[2J";
	try
	{
		Bureaucrat	*b = new Bureaucrat("Bob", 30);
		Form		*f = new Form("Form1", 50, 25);
		Form		*f1 = new Form("Form2", 10, 25);
		std::cout << *b << std::endl;
		std::cout << *f << std::endl;
		b->signForm(*f);
		std::cout << *f << std::endl;
		std::cout << *f1 << std::endl;
		b->signForm(*f1);
		std::cout << *f1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
