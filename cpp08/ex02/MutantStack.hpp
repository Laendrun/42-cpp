/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:11:30 by saeby             #+#    #+#             */
/*   Updated: 2023/04/15 21:24:25 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP
# include <iostream>
# include <algorithm>
# include <vector>
# include <stack>
# define _RESET "\e[0m"
# define _RED "\e[31m"
# define _GREEN "\e[32m"
# define _YELLOW "\e[33m"
# define _CYAN "\e[36m"

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack<T>(void);
		MutantStack<T>(const MutantStack<T> &ms);
		~MutantStack<T>();

		MutantStack<T>	&operator=(const MutantStack<T> &ms);

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin(void);
		iterator	end(void);
};
#endif