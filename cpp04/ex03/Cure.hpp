/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:51:03 by saeby             #+#    #+#             */
/*   Updated: 2023/02/22 13:53:33 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class	ICharacter;

class	Cure : virtual public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &c);
		~Cure();
		Cure	&operator=(const Cure &c);
		Cure	*clone() const;
		void	use(ICharacter &target);
};

#endif