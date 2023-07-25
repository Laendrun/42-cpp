/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:30:41 by saeby             #+#    #+#             */
/*   Updated: 2023/02/22 11:37:15 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class	ICharacter;

class Ice : virtual public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &i);
		~Ice();
		Ice		&operator=(const Ice &i);
		Ice		*clone() const;
		void	use(ICharacter &target);
};

#endif