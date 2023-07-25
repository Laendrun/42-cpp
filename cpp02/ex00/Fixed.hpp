/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:09:29 by saeby             #+#    #+#             */
/*   Updated: 2023/01/21 11:40:49 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &f);
		Fixed &operator=(const Fixed &f);	// this lets us define what is done when we set a Fixed = otherFixed
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
	int					_val;
	static const int	_bits = 8;
};

#endif
