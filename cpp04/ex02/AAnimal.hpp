/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:30:05 by saeby             #+#    #+#             */
/*   Updated: 2023/02/22 08:42:18 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <iostream>
# define _RESET "\e[0m"
# define _RED "\e[31m"
# define _GREEN "\e[32m"
# define _YELLOW "\e[33m"

// https://www.geeksforgeeks.org/virtual-destructor/
// https://www.geeksforgeeks.org/virtual-function-cpp/

class	AAnimal
{
	public:
		AAnimal(void);
		AAnimal(std::string type);
		AAnimal(AAnimal &a);
		virtual ~AAnimal();
		AAnimal &operator=(const AAnimal &a);
		void virtual	makeSound(void) const = 0;
		std::string	getType(void) const;
	protected:
		std::string	_type;
};

#endif