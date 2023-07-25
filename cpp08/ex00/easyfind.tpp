/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:19:08 by saeby             #+#    #+#             */
/*   Updated: 2023/04/13 11:50:21 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP
# include "easyfind.hpp"
# define _RESET "\e[0m"
# define _RED "\e[31m"
# define _GREEN "\e[32m"
# define _YELLOW "\e[33m"
# define _CYAN "\e[36m"

template <typename T>
void	easyfind(T& cont, int val)
{
	// if not found, std::find will return a pointer to the last element of the container
	// so if std::find != cont.end() => which is the last element
	// this means the value was found
	if (std::find(cont.begin(), cont.end(), val) != cont.end())
		std::cout << _GREEN << "Value: " << val << " found." << _RESET << std::endl;
	else
		std::cout << _RED << "Value: " << val << " not found." << _RESET << std::endl;
}

template <typename T>
void	test(std::string n, T& cont, int val)
{
	std::cout << _CYAN << "Trying to find value: " << val << " into container type: " << n << _RESET << std::endl;
	easyfind(cont, val);
}

#endif