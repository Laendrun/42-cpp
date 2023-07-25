/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:12:50 by saeby             #+#    #+#             */
/*   Updated: 2023/04/03 21:12:56 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

// https://www.geeksforgeeks.org/templates-cpp/

template <typename T> T max(T i, T j)
{
	return (i > j) ? i : j;
}

template <typename T> T min(T i, T j)
{
	return (i < j) ? i : j;
}

template <typename T> void swap(T& i, T& j)
{
	T	t;
	t = i;
	i = j;
	j = t;
}

#endif