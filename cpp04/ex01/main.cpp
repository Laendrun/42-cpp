/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:38:46 by saeby             #+#    #+#             */
/*   Updated: 2023/04/01 14:30:33 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#define ELEMENTS 4

int	main(void)
{
	std::cout << "\e[1;1H\e[2J";
	Animal* animals[ELEMENTS];
	for (int i = 0; i < ELEMENTS / 2; i++)
		animals[i] = new Cat();
	std::cout << std::endl;
	for (int i = ELEMENTS / 2; i < ELEMENTS; i++)
		animals[i] = new Dog();

	std::cout << std::endl;
	for (int i = 0; i < ELEMENTS; i++)
	{
		std::cout << "Type: " << animals[i]->getType() << ", sound: ";
		animals[i]->makeSound();
	}
	std::cout << std::endl;
	for (int i = 0; i < ELEMENTS; i++)
		delete animals[i];

	return (0);
}