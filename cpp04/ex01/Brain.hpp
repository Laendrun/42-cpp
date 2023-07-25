/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:40:01 by saeby             #+#    #+#             */
/*   Updated: 2023/02/21 20:13:48 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class	Brain
{
	public:
		Brain(void);
		Brain(Brain &b);
		~Brain();
		Brain &operator=(const Brain &b);
	protected:
		std::string	_ideas[100];
};

#endif