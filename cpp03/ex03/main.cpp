/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:18:30 by saeby             #+#    #+#             */
/*   Updated: 2023/01/22 14:22:34 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "\e[1;1H\e[2J";
	DiamondTrap michel("Michel");
	// Displaying starting status of both ClapTrap

	// Displaying ending status of both ClapTrap
	michel.whoami();
	return (0);
}