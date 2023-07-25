/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:00:42 by saeby             #+#    #+#             */
/*   Updated: 2023/01/22 11:15:42 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(std::string name, uint hp, uint ep, uint ad);
		FragTrap(FragTrap &ft);
		~FragTrap();
		FragTrap &operator=(const FragTrap &ft);

		void	attack(const std::string &target);
		void	highFivesGuys(void);
};

#endif