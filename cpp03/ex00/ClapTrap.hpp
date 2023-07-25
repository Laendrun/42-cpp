/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:10:24 by saeby             #+#    #+#             */
/*   Updated: 2023/01/21 18:46:15 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# define _RESET "\e[0m"
# define _RED "\e[31m"
# define _GREEN "\e[32m"
# define _YELLOW "\e[33m"
# define uint unsigned int

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(std::string name, uint hp, uint ep, uint ad);
		ClapTrap(ClapTrap &ct);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &ct);
	
		void	attack(const std::string &target);
		void	takeDamage(uint amount);
		void	beRepaired(uint amount);
		void	status(void);
		void	setHp(uint hp);
		uint	getHp(void);
		void	setEp(uint ep);
		uint	getEp(void);
		void	setAd(uint amount);
		uint	getAd(void);
	private:
		std::string		_name;
		uint			_hp;
		uint			_ep;
		uint			_ad;
};

#endif