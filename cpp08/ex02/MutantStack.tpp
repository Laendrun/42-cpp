/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:04:25 by saeby             #+#    #+#             */
/*   Updated: 2023/04/15 21:24:24 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_TPP
# define MUTANT_STACK_TPP
# include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void) {};

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &ms)
{
	*this = ms;
}

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack<T> &ms)
{
	*this = ms;
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack<T>(void) {};

template <typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template <typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::end(void)
{
	return (this->c.end());
}

#endif