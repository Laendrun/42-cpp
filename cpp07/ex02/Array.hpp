/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:42:58 by saeby             #+#    #+#             */
/*   Updated: 2023/04/10 08:30:09 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# define _RESET "\e[0m"
# define _RED "\e[31m"
# define _GREEN "\e[32m"
# define _YELLOW "\e[33m"

template <class T>
class Array
{
	public:
		Array<T>(void);
		Array<T>(int n);
		Array<T>(const Array& a);
		~Array<T>();
		Array<T>	&operator=(const Array<T> &a);
		T			&operator[](int i) const;

		int			size(void) const;
		void		setSize(int size);

		class IndexOutOfBoundsException : public std::exception
		{
			virtual const char *what(void) const throw()
			{
				return ("Index out of bounds");
			}
		};
	private:
		T	*_arr;
		int	_size;
};

#endif