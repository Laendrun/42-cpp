/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:23:42 by saeby             #+#    #+#             */
/*   Updated: 2023/02/22 18:01:13 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"
# include <iostream>

// class IMateriaSource;

class MateriaSource : virtual public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &ms);
		MateriaSource	&operator=(const MateriaSource &ms);
		~MateriaSource();
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const &type);
	private:
		AMateria	*_templates[4];
};

#endif