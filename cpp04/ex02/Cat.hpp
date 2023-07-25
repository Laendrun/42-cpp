/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:35:14 by saeby             #+#    #+#             */
/*   Updated: 2023/02/22 08:42:32 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>
# define _RESET "\e[0m"
# define _RED "\e[31m"
# define _GREEN "\e[32m"
# define _YELLOW "\e[33m"

class Cat : virtual public AAnimal
{
	public:
		Cat(void);
		Cat(Cat &cat);
		virtual ~Cat();
		Cat &operator=(const Cat &cat);
		void	makeSound(void) const;
	private:
		Brain	*_brain;
};

#endif