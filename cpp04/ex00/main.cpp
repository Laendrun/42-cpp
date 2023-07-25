/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:00:54 by saeby             #+#    #+#             */
/*   Updated: 2023/02/18 17:52:58 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int	main(void)
{
	std::cout << "\e[1;1H\e[2J";
	std::cout << _GREEN << "Correct animals." << _RESET << std::endl;
	const Animal*	meta = new Animal();
	const Animal*	i = new Cat();
	const Animal*	j = new Dog();

	std::cout << std::endl;
	std::cout << "Type: " << j->getType() << " sound: "; 
	j->makeSound();
	std::cout << "Type: " << i->getType() << " sound: ";
	i->makeSound();
	std::cout << "Type: " << meta->getType() << " sound: ";
	meta->makeSound();
	std::cout << std::endl;
	delete(meta);
	delete(i);
	delete(j);

	std::cout << _RED << "Wrong animals." << _RESET << std::endl;
	const WrongAnimal*	metaW = new WrongAnimal();
	const WrongAnimal*	iw = new WrongCat();
	const WrongAnimal*	jw = new WrongDog();

	std::cout << std::endl;
	std::cout << "Type: " << jw->getType() << " sound: "; 
	jw->makeSound();
	std::cout << "Type: " << iw->getType() << " sound: ";
	iw->makeSound();
	std::cout << "Type: " << metaW->getType() << " sound: ";
	metaW->makeSound();
	std::cout << std::endl;
	delete(metaW);
	return (0);
}