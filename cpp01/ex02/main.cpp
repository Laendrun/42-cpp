/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:15:51 by saeby             #+#    #+#             */
/*   Updated: 2023/02/17 21:10:56 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Printing the addresses" << std::endl << std::endl;

	std::cout << "Memory address of str:              " << &str << std::endl;

	std::cout << "Memory address stored in stringPTR: " << stringPTR << std::endl;

	std::cout << "Memory address stored in stringREF: " << &stringREF << std::endl << std::endl;

	std::cout << "Printing the values" << std::endl << std::endl;

	std::cout << "Value of str:                  " << str << std::endl;

	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;

	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
}
