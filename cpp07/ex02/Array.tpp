/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:06:33 by saeby             #+#    #+#             */
/*   Updated: 2023/04/10 09:06:44 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP
# include "Array.hpp"


// Constructors

template <class T>
Array<T>::Array(void)
{
	// std::cout << "Default array constructor" << std::endl;
	this->_arr = new T[0];
	this->_size = 0;
	return ;
}

template <class T>
Array<T>::Array(int n)
{
	// std::cout << "Unsigned int array constructor" << std::endl;
	this->_arr = new T[n];
	this->_size = n;
	return ;
}

template <class T>
Array<T>::Array(const Array<T> &a)
{
	// std::cout << "Copy constructor" << std::endl;
	this->_arr = new T[a.size()];
	this->_size = a.size();
	for (int i = 0; i < this->_size; i++)
		(this->_arr)[i] = a[i];
}

// // Constructors
// Destructor

template <class T>
Array<T>::~Array()
{
	// std::cout << "Destructor called" << std::endl;
	return ;
}

// // Destructor
// Operators overload

template <class T>
Array<T>	&Array<T>::operator=(const Array<T> &a)
{
	this->_size = a.size();
	return (*this);
}

template <class T>
T	&Array<T>::operator[](int i) const
{
	if(i >= this->_size || i < 0)
		throw (IndexOutOfBoundsException());
	return this->_arr[i];
}

// // Operators overload
// Member functions

template <class T>
int	Array<T>::size(void) const
{
	return (this->_size);
}

template <class T>
void	Array<T>::setSize(int size)
{
	this->_size = size;
}

// // Member functions

template <class T>
void	printArr(Array<T> &arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i];
		std::cout << " ";
	}
	std::cout << std::endl;
}

#endif
