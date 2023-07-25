/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:25:13 by saeby             #+#    #+#             */
/*   Updated: 2023/04/01 22:41:13 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP
# include <iostream>
# include <climits>

class ScalarConverter
{
	public:
		typedef struct s_spe
		{
			std::string	key;
			std::string	c;
			std::string	i;
			std::string	f;
			std::string	d;
		}	t_spe;

		static void	convert(std::string value);
		static bool	isChar(std::string value);
		static bool	isInt(std::string value);
		static bool	isDouble(std::string value);
		static bool	isFloat(std::string value);
		static bool	isSpecial(std::string value, t_spe *s);

		static void	print(char c);
		static void	print(int i);
		static void	print(double d);
		static void print(float f);
		static void	print(t_spe s);

		class UnknownCastException : public std::exception
		{
			virtual const char *what(void) const throw()
			{
				return ("No logical cast found for this value.");
			}
		};
};

#endif