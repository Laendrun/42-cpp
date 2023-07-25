/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:37:03 by saeby             #+#    #+#             */
/*   Updated: 2023/02/18 15:39:27 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP
# include <iostream>
# define _RESET "\e[0m"
# define _RED "\e[31m"
# define _GREEN "\e[32m"
# define _YELLOW "\e[33m"

class	WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal &a);
		~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &a);
		void		makeSound(void) const;
		std::string	getType(void) const;
	protected:
		std::string	_type;
};

#endif