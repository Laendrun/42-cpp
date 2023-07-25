/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:30:05 by saeby             #+#    #+#             */
/*   Updated: 2023/02/18 15:33:20 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# define _RESET "\e[0m"
# define _RED "\e[31m"
# define _GREEN "\e[32m"
# define _YELLOW "\e[33m"

// https://www.geeksforgeeks.org/virtual-destructor/
// https://www.geeksforgeeks.org/virtual-function-cpp/

class	Animal
{
	public:
		Animal(void);
		Animal(std::string type);
		Animal(Animal &a);
		virtual ~Animal();
		Animal &operator=(const Animal &a);
		void virtual	makeSound(void) const;
		std::string	getType(void) const;
	protected:
		std::string	_type;
};

#endif