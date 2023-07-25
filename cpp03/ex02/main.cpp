/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:18:30 by saeby             #+#    #+#             */
/*   Updated: 2023/01/22 11:18:06 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "\e[1;1H\e[2J";
	ClapTrap michel("Michel");
	ClapTrap denis("Denis", 15, 10, 5);
	ScavTrap jean("Jean");
	FragTrap tobias("Tobias");

	// Displaying starting status of both ClapTrap
	michel.status();
	denis.status();
	jean.status();
	tobias.status();

	michel.attack("Denis");
	denis.takeDamage(michel.getAd());
	jean.attack("Michel");
	michel.takeDamage(jean.getAd());
	denis.beRepaired(4);
	denis.attack("Tobias");
	tobias.takeDamage(denis.getAd());
	tobias.highFivesGuys();
	jean.guardGate();

	// Displaying ending status of both ClapTrap
	michel.status();
	denis.status();
	jean.status();
	tobias.status();
	return (0);
}