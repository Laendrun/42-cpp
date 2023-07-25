/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:33:00 by saeby             #+#    #+#             */
/*   Updated: 2023/02/18 17:35:27 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_DOG_HPP
# define WRONG_DOG_HPP
# include "WrongAnimal.hpp"
# include <iostream>
# define _RESET "\e[0m"
# define _RED "\e[31m"
# define _GREEN "\e[32m"
# define _YELLOW "\e[33m"

class WrongDog : virtual public WrongAnimal
{
	public:
		WrongDog(void);
		WrongDog(WrongDog &dog);
		~WrongDog();
		WrongDog &operator=(const WrongDog &dog);
		void	makeSound(void) const;
};

#endif
