/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:40:26 by saeby             #+#    #+#             */
/*   Updated: 2023/02/17 21:13:02 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
#include "Weapon.hpp"

class HumanB
{
	public:
				HumanB(std::string name);
				~HumanB(void);
		void	attack();
		void	setWeapon(Weapon& weapon);
	private:
		std::string	name;
		Weapon		*weapon;
};

#endif
