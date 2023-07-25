/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:18:30 by saeby             #+#    #+#             */
/*   Updated: 2023/01/21 19:15:57 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "\e[1;1H\e[2J";
	ClapTrap michel("Michel");
	ClapTrap denis("Denis", 15, 10, 5);

	// Displaying starting status of both ClapTrap
	michel.status();
	denis.status();

	michel.attack("Denis");
	denis.takeDamage(michel.getAd());
	michel.setAd(2);
	michel.attack("Denis");
	denis.takeDamage(michel.getAd());
	denis.beRepaired(4);

	// Displaying ending status of both ClapTrap
	michel.status();
	denis.status();
	return (0);
}