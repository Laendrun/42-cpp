/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:49:28 by saeby             #+#    #+#             */
/*   Updated: 2023/05/01 11:32:05 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP
# include <iostream>
# include <vector>
# include <list>
# include <set>
# include <sys/time.h>

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &pm);
		~PmergeMe();
		PmergeMe	&operator=(const PmergeMe &pm);

		std::vector<int>	fjmi(std::vector<int> A);
		void	fjmi(std::list<int> B);
		std::vector<int>	parseAsVec(int ac, char **av);
		std::list<int>		parseAsList(int ac, char **av);
		double	getTime(void);
		double	getDelta(double time);
		bool	checkInput(std::vector<int> A);
		bool	checkInput(std::list<int> A);
		class InvalidArgumentException : public std::exception
		{
			virtual const char *what(void) const throw()
			{
				return ("Error. Invalid argument.");
			}
		};
		class DuplicateValueException : public std::exception
		{
			virtual const char *what(void) const throw()
			{
				return ("Error. Duplicate value in arguments.");
			}
		};
	private:
		std::vector<std::vector<int> >	createPairs(std::vector<int> A);
		std::list<std::vector<int> >	createPairs(std::list<int> A);
		std::vector<std::vector<int> >	sortPairs(std::vector<std::vector<int> > split_array);
		std::list<std::vector<int> >	sortPairs(std::list<std::vector<int> > split_array);
		std::vector<std::vector<int> >	sortByLargerValue(std::vector<std::vector<int> > sorted_split);
		int								jacobstahl(int n);
		std::vector<int>				build_jacob_insertion_sequence(std::vector<int> pend);
		std::vector<int>::iterator		bisect(std::vector<int>& A, int item);
		std::list<int>::iterator		bisect(std::list<int>& A, int item);
		std::vector<int>				createS(std::vector<std::vector<int> > sorted_split, int straggler);
		std::list<int>					createS(std::list<std::vector<int> > sorted_split, int straggler);
		std::vector<int>				createS(std::vector<std::vector<int> > sorted_split);
		std::list<int>					createS(std::list<std::vector<int> > sorted_split);
		void							print_s(std::vector<int> S);
		void							print_s(std::list<int> S);
		void							print_split(std::vector<std::vector<int> > S);
		void							print_split(std::list<std::vector<int> > S);
};

bool							sortByLargerValueList(const std::vector<int>& first, const std::vector<int>& second);

#endif
