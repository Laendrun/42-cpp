/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:24:37 by saeby             #+#    #+#             */
/*   Updated: 2023/02/18 15:33:29 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include <iostream>
# define _RESET "\e[0m"
# define _RED "\e[31m"
# define _GREEN "\e[32m"
# define _YELLOW "\e[33m"

class Dog : virtual public Animal
{
	public:
		Dog(void);
		Dog(Dog &dog);
		virtual ~Dog();
		Dog &operator=(const Dog &dog);
		void	makeSound(void) const;
};

#endif