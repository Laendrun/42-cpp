/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:53:16 by saeby             #+#    #+#             */
/*   Updated: 2023/02/17 21:09:50 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cout << "./ex01 <name> <quantity>" << std::endl;
		return (1);
	}

	std::string	name = av[1];
	int			n = std::atoi(av[2]);

	std::cout << "Testing with " << n << " zombies named " << name << std::endl;
	std::cout << "Taking " << n << " zombies out of ground..." << std::endl;
	Zombie	*horde = zombieHorde(n, name);

	std::cout << "They announce themselves" << std::endl;
	for (int i = 0; i < n; i++)
		horde[i].announce();

	std::cout << "I'll now burry them again..." << std::endl;
	delete [] horde;
	return (0);
}
