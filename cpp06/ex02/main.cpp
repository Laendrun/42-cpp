/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 23:45:59 by saeby             #+#    #+#             */
/*   Updated: 2023/04/03 19:58:56 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// https://stackoverflow.com/questions/351845/finding-the-type-of-an-object-in-c

/*
void identify(Base* p);
It prints the actual type of the object pointed to by p: "A", "B" or "C"
*/
void	identify(Base* p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "Type A pointer" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "Type B pointer" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "Type C pointer" << std::endl;
	return ;
}

/*
void identify(Base& p);
It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
inside this function is forbidden.
*/
void	identify(Base& p)
{
	try
	{
		A a = dynamic_cast<A &>(p);
		std::cout << "Type A reference" << std::endl;
		return ;
	}
	catch (std::exception &e) {};
	try
	{
		B b = dynamic_cast<B &>(p);
		std::cout << "Type B reference" << std::endl;
		return ;
	}
	catch (std::exception &e) {};
	try
	{
		C c = dynamic_cast<C &>(p);
		std::cout << "Type C reference" << std::endl;
		return ;
	}
	catch (std::exception &e) {};
	return ;
}

int roll(int max)
{
	srand(time(0));
	return (rand() % max);
}

/*
Base * generate(void);
It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
to use anything you like for the random choice implementation.
*/
Base	*generate(void)
{
	int t = roll(3);
	switch (t)
	{
		case 0:
			std::cout << "New A generated" << std::endl;
			return (new A());
		case 1:
			std::cout << "New B generated" << std::endl;
			return (new B());
		case 2:
			std::cout << "New C generated" << std::endl;
			return (new C());
		default :
			std::cout << "New A generated" << std::endl;
			return (new A());
	}
}

int	main(void)
{
	Base	*p;

	p = generate();
	identify(p);
	identify(*p);
	delete (p);
	return (0);
}