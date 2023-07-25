/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:25:05 by saeby             #+#    #+#             */
/*   Updated: 2023/04/05 15:51:20 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	ScalarConverter::convert(std::string value)
{
	t_spe	special;

	if (ScalarConverter::isSpecial(value, &special))
	{
		ScalarConverter::print(special);
		return ;
	}
	if (ScalarConverter::isChar(value))
	{
		ScalarConverter::print(value[0]);
		return ;
	}
	if (ScalarConverter::isInt(value))
	{
		ScalarConverter::print(std::stoi(value));
		return ;
	}
	if (ScalarConverter::isFloat(value))
	{
		ScalarConverter::print(std::stof(value));
		return ;
	}
	if (ScalarConverter::isDouble(value))
	{
		ScalarConverter::print(std::stod(value));
		return ;
	}
	throw(ScalarConverter::UnknownCastException());
}

bool	ScalarConverter::isSpecial(std::string value, t_spe *s)
{
	ScalarConverter::t_spe	specials[] =
	{
		{"+inff", "impossible", "impossible", "inff", "inf"},
		{"inff", "impossible", "impossible", "inff", "inf"},
		{"-inff", "impossible", "impossible", "-inff", "-inf"},
		{"nanf", "impossible", "impossible", "nanf", "nan"},
		{"+inf", "impossible", "impossible", "inff", "inf"},
		{"inf", "impossible", "impossible", "inff", "inf"},
		{"-inf", "impossible", "impossible", "-inff", "-inf"},
		{"nan", "impossible", "impossible", "nanf", "nan"},
		{"", "", "", "", ""}
	};

	int	i = 0;
	while ((specials[i].key).length() != 0)
	{
		if (value == specials[i].key)
		{
			s->key = specials[i].key;
			s->c = specials[i].c;
			s->d = specials[i].d;
			s->f = specials[i].f;
			s->i = specials[i].i;
			return (1);
		}
		i++;
	}
	return (0);
}

bool	ScalarConverter::isChar(std::string value)
{
	if (value.length() != 1 || std::isdigit(value[0]) || !std::isprint(value[0]))
		return (0);
	return(1);
}

bool	ScalarConverter::isInt(std::string value)
{
	int				i = 0;
	long long int	num;

	while (std::isspace(value[i]))
		++i;
	if (value[i] == '+' || value[i] == '-')
		++i;
	if (value[i] == '\0' || !std::isdigit(value[i]))
		return (0);
	++i;
	while (value[i] != '\0')
	{
		if (!std::isdigit(value[i]))
			return (0);
		i++;
	}
	num = std::stoll(value);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

bool	ScalarConverter::isDouble(std::string value)
{
	int				i = 0;
	long long int	num;
	bool			dot = false;

	while (std::isspace(value[i]))
		++i;
	if (value[i] == '+' || value[i] == '-')
		++i;
	if (value[i] == '\0' || (!std::isdigit(value[i]) && value[i] != '.'))
		return (0);
	++i;
	while (value[i] != '\0')
	{
		if (!std::isdigit(value[i]))
		{
			if (value[i] != '.')
				return (0);
			if (value[i] == '.' && dot)
				return (0);
			else
				dot = true;
		}
		++i;
	}
	num = std::stoll(value);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	if (!dot)
		return (0);
	return (1);
}

bool	ScalarConverter::isFloat(std::string value)
{
	int				i = 0;
	long long int	num;
	bool			dot = false;

	while (std::isspace(value[i]))
		++i;
	if (value[i] == '+' || value[i] == '-')
		++i;
	if (value[i] == '\0' || (!std::isdigit(value[i]) && value[i] != '.'))
		return (0);
	++i;
	while (value[i] != '\0' && value[i] != 'f')
	{
		if (!std::isdigit(value[i]))
		{
			if (value[i] != '.')
				return (0);
			if (value[i] == '.' && dot)
				return (0);
			else
				dot = true;
		}
		++i;
	}
	if (value[i] == '\0')
		return (0);
	num = std::stoll(value);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

void	ScalarConverter::print(char c)
{
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);

	std::cout << "Original: char" << std::endl;
	std::cout << "char : \'" << c << "\'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
	return ;
}

void	ScalarConverter::print(int i)
{
	char	c = static_cast<char>(i);
	float	f = static_cast<float>(i);
	double	d = static_cast<double>(i);

	std::cout << "Original: int" << std::endl;
	std::cout << "char: ";
	if (i < CHAR_MIN || i > CHAR_MAX || !std::isprint(i))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << c << "\'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << i << ".0f" << std::endl;
	(void) f;
	std::cout << "double: " << i << ".0" << std::endl;
	(void) d;
	// std::cout << "double: " << d << ".0" << std::endl; // try with 2147483648 (any big number)
	// std::cout << "float: " << f << ".0f" << std::endl; // try with 2147483648 (any big number)
	return ;
}

void	ScalarConverter::print(double d)
{
	char	c = static_cast<char>(d);
	int		i = static_cast<int>(d);
	float	f = static_cast<float>(d);

	std::cout << "Original: double" << std::endl;
	std::cout << "char: ";
	if (i < CHAR_MIN || i > CHAR_MAX || !std::isprint(i))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << c << "\'" << std::endl;
	std::cout << "int: " << i << std::endl;
	if (f == i)
		std::cout << "float: " << i << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	if (d == i)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
	return ;
}

void	ScalarConverter::print(float f)
{
	char	c = static_cast<char>(f);
	int		i = static_cast<int>(f);
	double	d = static_cast<double>(f);

	std::cout << "Original: float" << std::endl;
	std::cout << "char: ";
	if (i < CHAR_MIN || i > CHAR_MAX || !std::isprint(i))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << c << "\'" << std::endl;
	std::cout << "int: " << i << std::endl;
	if (f == i)
		std::cout << "float: " << i << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	if (d == i)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
	return ;
}

void	ScalarConverter::print(t_spe s)
{
	std::cout << "Original: special" << std::endl;
	std::cout << "char: " << s.c << std::endl;
	std::cout << "int: " << s.i << std::endl;
	std::cout << "float: " << s.f << std::endl;
	std::cout << "double: " << s.d << std::endl;
	return ;
}
