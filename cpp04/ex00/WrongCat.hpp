/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:49:01 by saeby             #+#    #+#             */
/*   Updated: 2023/02/18 17:35:26 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP
# include "WrongAnimal.hpp"
# include <iostream>
# define _RESET "\e[0m"
# define _RED "\e[31m"
# define _GREEN "\e[32m"
# define _YELLOW "\e[33m"

class WrongCat : virtual public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(WrongCat &cat);
		~WrongCat();
		WrongCat &operator=(const WrongCat &cat);
		void	makeSound(void) const;
};

#endif