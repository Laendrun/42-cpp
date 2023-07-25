/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:18:30 by saeby             #+#    #+#             */
/*   Updated: 2023/01/22 10:25:42 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "\e[1;1H\e[2J";
	ClapTrap michel("Michel");
	ClapTrap denis("Denis", 15, 10, 5);
	ScavTrap jean("Jean");

	// Displaying starting status of both ClapTrap
	michel.status();
	denis.status();

	michel.attack("Denis");
	denis.takeDamage(michel.getAd());
	jean.attack("Michel");
	michel.takeDamage(jean.getAd());
	denis.beRepaired(4);
	jean.guardGate();

	// Displaying ending status of both ClapTrap
	michel.status();
	denis.status();
	return (0);
}