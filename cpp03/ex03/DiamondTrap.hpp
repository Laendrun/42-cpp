/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:26:33 by saeby             #+#    #+#             */
/*   Updated: 2023/01/22 13:47:18 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>

// https://www.geeksforgeeks.org/virtual-base-class-in-c/
// -> ClapTrap.hpp

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap &dt);
		~DiamondTrap();
		DiamondTrap &operator=(const DiamondTrap &dt);

		void	attack(const std::string &target);
		void	whoami(void);
	private:
		std::string	_name;
};

#endif