/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:49:41 by saeby             #+#    #+#             */
/*   Updated: 2023/02/17 21:53:30 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(const Fixed f1, const Fixed f2);
		Point(const Point &p);

		~Point(void);

		Point	&operator=(const Point &p);
		static bool	sign(const Point &a, const Point &b, const Point &c, const Point &d);
	private:
		Fixed	_x;
		Fixed	_y;
};

#endif
