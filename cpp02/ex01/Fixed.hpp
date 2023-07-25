/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:09:29 by saeby             #+#    #+#             */
/*   Updated: 2023/01/21 13:14:10 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &f);
		Fixed(const int i);
		Fixed(const float f);
		~Fixed(void);
		Fixed &operator=(const Fixed &f);	// this lets us define what is done when we set a Fixed = otherFixed
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	private:
	int					_val;
	static const int	_bits = 8;
};

std::ostream &operator<<(std::ostream &o, const Fixed &f);

#endif
