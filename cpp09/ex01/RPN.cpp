/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:48:47 by saeby             #+#    #+#             */
/*   Updated: 2023/04/24 21:04:10 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) : _res(0) {}

RPN::RPN(const RPN& r)
{
	*this = r;
}

RPN::~RPN(void) {}

RPN	&RPN::operator=(const RPN& r)
{
	if (this != &r)
	{
		this->_res = r._res;
		this->_stack = r._stack;
	}
	return (*this);
}

int	RPN::getResult(void) const
{
	return (this->_res);
}

void	RPN::rpn(const std::string expression)
{
	std::string	sNum;

	for (unsigned long i = 0; i < expression.length(); i++)
	{
		char	c = expression[i];
		if (c == ' ')
			continue ;
		else if (std::isdigit(c))
			sNum += c;
		else if (this->isOperator(c))
		{
			// stack size should be minimum 2
			if (this->_stack.size() < 2)
				throw (RPN::NotEnoughOperandsException());
			int num2 = this->_stack.top();
			this->_stack.pop();
			int num1 = this->_stack.top();
			this->_stack.pop();
			this->doOp(num1, num2, c);
			// num2 of operation is the one on top of the stack
			// num1 of operation is the second one from the top of the stack
			// do operation and add result to the stack
			//std::cout << "Should do operation here" << std::endl;
		}
		else 
			throw (RPN::UnknownValueException());
		if (!sNum.empty())
		{
			this->_stack.push(std::atoi(sNum.c_str()));
			sNum.clear();
		}
	}
	// once the for loop has ended, there should be only one element left in stack
	if (this->_stack.size() != 1)
		throw (RPN::TooManyOperandsException());
	this->_res = this->_stack.top();
	this->_stack.pop();
}

bool	RPN::isOperator(char c) const
{
	return (c == '+' || c == '-' || c == '/' || c == '*');
}

void	RPN::doOp(int num1, int num2, char op)
{
	switch (op)
	{
		case '+':
			this->_stack.push(num1 + num2);
			break ;
		case '-':
			this->_stack.push(num1 - num2);
			break ;
		case '/':
			if (num2 == 0)
				throw (RPN::DivisionByZeroException());
			this->_stack.push(num1 / num2);
			break ;
		case '*':
			this->_stack.push(num1 * num2);
			break ;
	}
}
