/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:06:15 by saeby             #+#    #+#             */
/*   Updated: 2023/04/15 17:57:35 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <climits>
# include <vector>
# include <iostream>
# define _RESET "\e[0m"
# define _RED "\e[31m"
# define _GREEN "\e[32m"
# define _YELLOW "\e[33m"
# define _CYAN "\e[36m"

class	Span
{
	public:
		Span(unsigned int N);
		Span(const Span& s);
		~Span();
		Span &operator=(const Span &s);
		void	addNumber(int N);
		void	addNumber(std::vector<int>::iterator b, std::vector<int>::iterator e);
		unsigned int		shortestSpan(void) const;
		unsigned int		longestSpan(void) const;
		std::vector<int>	getContent(void) const;
		unsigned int		getSize(void) const;
		
		class NotEnoughRoomException : public std::exception
		{
			virtual const char *what(void) const throw()
			{
				return ("Not enough space in Span to add new number.");
			}
		};
		class NotEnoughElementsException : public std::exception
		{
			virtual const char *what(void) const throw()
			{
				return ("Not enough elements to find a valid Span.");
			}
		};
	private:
		Span(void) {};
		unsigned int				_size;
		std::vector<int>			_content;
};

std::ostream &operator<<(std::ostream &o, const Span &s);

template <typename T> T max(T i, T j)
{
	return (i > j) ? i : j;
}

template <typename T> T min(T i, T j)
{
	return (i < j) ? i : j;
}

#endif