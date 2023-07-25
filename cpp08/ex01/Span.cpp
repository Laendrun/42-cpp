/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:08:47 by saeby             #+#    #+#             */
/*   Updated: 2023/04/15 18:08:48 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _size(N), _content(0) {};

Span::Span(const Span& s) {
	*this = s;
};

Span::~Span() {};

Span	&Span::operator=(const Span &s)
{
	this->_content = s._content;
	this->_size = s._size;
	return (*this);
}

void	Span::addNumber(int N)
{
	if (this->_content.size() >= this->_size)
		throw (Span::NotEnoughRoomException());
	else
		this->_content.push_back(N);
}

void	Span::addNumber(std::vector<int>::iterator b, std::vector<int>::iterator e)
{
	int	s = std::vector<int>(b, e).size();
	if (this->_content.size() + s > this->_size)
		throw (Span::NotEnoughRoomException());
	else
		this->_content.insert(this->_content.end(), b, e);
}

unsigned int	Span::shortestSpan(void) const
{
	if (this->_size <= 1)
		throw (Span::NotEnoughElementsException());

	std::vector<int>	copy(this->_content);
	sort(copy.begin(), copy.end());

	long	sSpan = (long) INT_MAX - (long) INT_MIN;
	int		minV = 0;
	int 	maxV = 0;

	for (unsigned int i = 0; i < copy.size() - 1; i++)
	{
		minV = min(copy[i], copy[i + 1]);
		maxV = max(copy[i], copy[i + 1]);
		sSpan = min(sSpan, (long) maxV - minV);
	}
	copy.clear();
	return ((unsigned int) sSpan);
}

unsigned int	Span::longestSpan(void) const
{
	if (this->_size <= 1)
		throw (Span::NotEnoughElementsException());
	int	minVal = *std::min_element(this->_content.begin(), this->_content.end());
	int maxVal = *std::max_element(this->_content.begin(), this->_content.end());
	return (maxVal - minVal);
}

// Getters

std::vector<int>	Span::getContent(void) const { return (this->_content); }

unsigned int		Span::getSize(void) const { return (this->_size); }

// -- Getters

// Helpers

std::ostream	&operator<<(std::ostream &o, const Span &s)
{
	std::vector<int>	content;
	unsigned int		size;

	content = s.getContent();
	size = s.getSize();
	o << "Span Size: " << size << ", content :" << std::endl;
	for (unsigned int i = 0; i < content.size(); i++)
		o << content[i] << " ";
	return (o);
}

// -- Helpers