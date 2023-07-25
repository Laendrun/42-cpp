/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:49:02 by saeby             #+#    #+#             */
/*   Updated: 2023/04/24 21:05:38 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stack>

class RPN
{
	public:
		RPN(void);
		RPN(const RPN& r);
		~RPN();
		RPN	&operator=(const RPN& r);

		int				getResult(void) const;
		void			rpn(const std::string expression);

		class DivisionByZeroException : public std::exception
		{
			virtual const char *what(void) const throw()
			{
				return ("Attempting a division by zero.");
			}
		};
		class TooManyOperandsException : public std::exception
		{
			virtual const char *what(void) const throw()
			{
				return ("Too many operands in the expression.");
			}
		};
		class NotEnoughOperandsException : public std::exception
		{
			virtual const char *what(void) const throw()
			{
				return ("Not enough operands in expression.");
			}
		};
		class UnknownValueException : public std::exception
		{
			virtual const char *what(void) const throw()
			{
				return ("Unknown value in expression.");
			}
		};
	private:
		bool			isOperator(char c) const;
		void			doOp(int num1, int num2, char op);
		std::stack<int>	_stack;
		int				_res;
};

#endif