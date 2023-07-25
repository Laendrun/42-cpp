/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:15:26 by saeby             #+#    #+#             */
/*   Updated: 2023/02/22 15:16:00 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp"

class	Character : virtual public ICharacter
{
	public:
		Character(void);
		Character(std::string name);
		Character(const Character &c);
		Character	&operator=(const Character &c);
		~Character();
		std::string const	&getName(void) const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);
	private:
		std::string	_name;
		AMateria	*_inventory[4];
};

#endif