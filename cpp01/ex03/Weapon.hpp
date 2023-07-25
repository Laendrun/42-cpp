/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:40:51 by saeby             #+#    #+#             */
/*   Updated: 2023/02/17 21:12:54 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon
{
	public:
							Weapon(std::string type);
							~Weapon(void);
		const std::string&	getType(void);
		void				setType(std::string type);
	private:
		std::string	type;
};

#endif
