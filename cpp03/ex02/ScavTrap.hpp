/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 09:49:13 by saeby             #+#    #+#             */
/*   Updated: 2023/01/22 11:02:41 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

// https://www.geeksforgeeks.org/inheritance-in-c/

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(std::string name, uint hp, uint ep, uint ad);
		ScavTrap(ScavTrap &st);
		~ScavTrap();
		ScavTrap &operator=(const ScavTrap &st);

		void	attack(const std::string &target);
		void	guardGate(void);
};

#endif