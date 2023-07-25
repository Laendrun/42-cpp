/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 22:46:52 by saeby             #+#    #+#             */
/*   Updated: 2023/04/01 23:38:41 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int	main(void)
{
	Data	d;
	Data	*deserialized;

	d.i = 42;
	d.val = "Born2Code";

	std::cout << "Original Data structure values:" << std::endl;
	std::cout << "Data.i (int): " << d.i << std::endl;
	std::cout << "Data.val (string): " << d.val << std::endl;
	std::cout << "Original address: " << static_cast<void *>(&d) << std::endl << std::endl;

	std::cout << "Serialization..." << std::endl;
	uintptr_t raw = Serializer::serialize(&d);
	std::cout << "Raw Data: " << raw << std::endl << std::endl;

	std::cout << "Deserialization..." << std::endl;
	deserialized = Serializer::deserialize(raw);
	std::cout << "All the following values should be the same as before serialization/deserialization" << std::endl << std::endl;

	std::cout << "Post-serialization / deserialization values:" << std::endl;
	std::cout << "deserialized.i (int): " << deserialized->i << std::endl;
	std::cout << "deserialized.val (string): " << deserialized->val << std::endl;
	std::cout << "Final address: " << static_cast<void *>(deserialized) << std::endl;

	return (0);
}