/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:15:18 by saeby             #+#    #+#             */
/*   Updated: 2023/02/22 15:11:21 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include "ICharacter.hpp"
# include <iostream>

class	ICharacter;

class	AMateria
{
	public:
		AMateria(void);
		AMateria(const std::string &type);
		AMateria(const AMateria &m);
		virtual ~AMateria();
		AMateria	&operator=(const AMateria &m);

		const std::string	&getType() const; // Returns the materia type
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
	protected:
		std::string			_type;
};

#endif