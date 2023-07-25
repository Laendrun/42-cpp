/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:16:24 by saeby             #+#    #+#             */
/*   Updated: 2023/05/01 11:31:15 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &pm)
{
	*this = pm;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &pm)
{
	if (this != &pm)
	{}
	return (*this);
}

PmergeMe::~PmergeMe() {}

// std::vector<int> fjmi

std::vector<int>	PmergeMe::fjmi(std::vector<int> A)
{
	std::vector<std::vector<int> > split;
	std::vector<std::vector<int> > sorted_split;
	std::vector<int> S;

	bool	hasStraggler = A.size() % 2;
	int		straggler;

	if (hasStraggler)
	{
		straggler = A.back();
		A.pop_back();
	}

	split = PmergeMe::createPairs(A);
	sorted_split = PmergeMe::sortPairs(split);
	sorted_split = PmergeMe::sortByLargerValue(sorted_split);

	if (hasStraggler)
		S = PmergeMe::createS(sorted_split, straggler);
	else
		S = PmergeMe::createS(sorted_split);

	return (S);
}

std::vector<std::vector<int> >	PmergeMe::createPairs(std::vector<int> A)
{
	std::vector<std::vector<int> >	split_array;
	std::vector<int>	temp_array;

	for (unsigned int i = 0; i < A.size(); i++)
	{
		unsigned int temp_len = temp_array.size();
		if (temp_len == 1)
		{
			temp_array.push_back(A[i]);
			split_array.push_back(temp_array);
			temp_array.clear();
		}
		else if (split_array.size() * 2 == A.size() - 1)
		{
			temp_array.push_back(A[i]);
			split_array.push_back(temp_array);
			temp_array.clear();
		}
		else if (temp_array.size() == 0)
			temp_array.push_back(A[i]);
	}
	return (split_array);
}

std::vector<std::vector<int> > PmergeMe::sortPairs(std::vector<std::vector<int> > split_array)
{
	for (unsigned int i = 0; i < split_array.size(); i++)
	{
		if (split_array[i].size() != 1 && split_array[i][0] > split_array[i][1])
		{
			int temp = split_array[i][0];
			split_array[i][0] = split_array[i][1];
			split_array[i][1] = temp;
		}
	}
	return (split_array);
}

std::vector<std::vector<int> > PmergeMe::sortByLargerValue(std::vector<std::vector<int> > sorted_split)
{
	for (unsigned int i = 0; i < sorted_split.size(); i++)
	{
		for (unsigned int j = i + 1; j < sorted_split.size(); j++)
		{
			if (sorted_split[j][1] < sorted_split[i][1])
			{
				std::vector<int> temp = sorted_split[i];
				sorted_split[i] = sorted_split[j];
				sorted_split[j] = temp;
			}
		}
	}
	return (sorted_split);
}

std::vector<int>::iterator	PmergeMe::bisect(std::vector<int>& A, int item)
{
	for (unsigned int i = 0; i < A.size(); i++)
	{
		if (A[i] > item)
			return (A.begin() + i);
	}
	return (A.end());
}

std::vector<int> PmergeMe::createS(std::vector<std::vector<int> > sorted_split, int straggler)
{
	std::vector<int> S;
	std::vector<int> pend;
	std::vector<int> jacob_seq;

	for (unsigned int i = 0; i < sorted_split.size(); i++)
	{
		S.push_back(sorted_split[i][1]);
		pend.push_back(sorted_split[i][0]);
	}
	S.insert(S.begin(), pend[0]);
	pend.erase(pend.begin());
	jacob_seq = PmergeMe::build_jacob_insertion_sequence(pend);

	unsigned int iterator = 1;
	unsigned int jacobindex = 3;
	std::vector<int> indexSeq;
	std::string last = "default";
	int item;
	std::vector<int>::iterator insertion_point;

	while (iterator <= pend.size())
	{
		if (jacob_seq.size() != 0 && last != "jacob")
		{
			indexSeq.push_back(jacob_seq[0]);
			item = pend[jacob_seq[0] - 1];
			jacob_seq.erase(jacob_seq.begin());
			last = "jacob";
		}
		else
		{
			if (std::find(indexSeq.begin(), indexSeq.end(), iterator) != indexSeq.end())
				iterator++;
			item = pend[iterator - 1];
			indexSeq.push_back(iterator);
			last = "not-jacob";
		}
		insertion_point = PmergeMe::bisect(S, item);
		S.insert(insertion_point, item);
		iterator++;
		jacobindex++;
	}

	insertion_point = PmergeMe::bisect(S, straggler);
	S.insert(insertion_point, straggler);
	return (S);
}

std::vector<int> PmergeMe::createS(std::vector<std::vector<int> > sorted_split)
{
	std::vector<int> S;
	std::vector<int> pend;
	std::vector<int> jacob_seq;

	for (unsigned int i = 0; i < sorted_split.size(); i++)
	{
		S.push_back(sorted_split[i][1]);
		pend.push_back(sorted_split[i][0]);
	}
	S.insert(S.begin(), pend[0]);
	pend.erase(pend.begin());
	jacob_seq = PmergeMe::build_jacob_insertion_sequence(pend);

	unsigned int iterator = 1;
	unsigned int jacobindex = 3;
	std::vector<int> indexSeq;
	std::string last = "default";
	int item;
	std::vector<int>::iterator insertion_point;

	while (iterator <= pend.size())
	{
		if (jacob_seq.size() != 0 && last != "jacob")
		{
			indexSeq.push_back(jacob_seq[0]);
			item = pend[jacob_seq[0] - 1];
			jacob_seq.erase(jacob_seq.begin());
			last = "jacob";
		}
		else
		{
			if (std::find(indexSeq.begin(), indexSeq.end(), iterator) != indexSeq.end())
				iterator++;
			item = pend[iterator - 1];
			indexSeq.push_back(iterator);
			last = "not-jacob";
		}
		insertion_point = PmergeMe::bisect(S, item);
		S.insert(insertion_point, item);
		iterator++;
		jacobindex++;
	}

	return (S);
}

// std::list fjmi

void	PmergeMe::fjmi(std::list<int> A)
{
	std::list<std::vector<int> > split;
	std::list<std::vector<int> > sorted_split;

	std::list<int> S;

	bool	hasStraggler = A.size() % 2;
	int		straggler;

	if (hasStraggler)
	{
		straggler = A.back();
		A.pop_back();
	}

	split = PmergeMe::createPairs(A);
	sorted_split = PmergeMe::sortPairs(split);
	sorted_split.sort(sortByLargerValueList);

	if (hasStraggler)
		S = PmergeMe::createS(sorted_split, straggler);
	else
		S = PmergeMe::createS(sorted_split);
}

std::list<std::vector<int> >	PmergeMe::createPairs(std::list<int> A)
{
	std::list<std::vector<int> >	split_array;
	std::vector<int>				temp_array;

	for (std::list<int>::iterator it = A.begin(); it != A.end(); it++)
	{
		unsigned int temp_len = temp_array.size();
		if (temp_len == 1)
		{
			temp_array.push_back(*it);
			split_array.push_back(temp_array);
			temp_array.clear();
		}
		else if (split_array.size() * 2 == A.size() - 1)
		{
			temp_array.push_back(*it);
			split_array.push_back(temp_array);
			temp_array.clear();
		}
		else if (temp_array.size() == 0)
			temp_array.push_back(*it);
	}
	return (split_array);
}

std::list<std::vector<int> >	PmergeMe::sortPairs(std::list<std::vector<int> > split_array)
{
	for (std::list<std::vector<int> >::iterator it = split_array.begin(); it != split_array.end(); it++)
	{
		if ((*it).size() != 1 && (*it)[0] > (*it)[1])
		{
			int temp = (*it)[0];
			(*it)[0] = (*it)[1];
			(*it)[1] = temp;
		}
	}
	return (split_array);
}

bool	sortByLargerValueList(const std::vector<int>& first, const std::vector<int>& second)
{
	if (first[1] < second[1])
		return (true);
	return (false);
}

std::list<int> PmergeMe::createS(std::list<std::vector<int> > sorted_split, int straggler)
{
	std::list<int> S;
	std::vector<int> pend;
	std::vector<int> jacob_seq;

	for (std::list<std::vector<int> >::iterator it = sorted_split.begin(); it != sorted_split.end(); it++)
	{
		S.push_back((*it)[1]);
		pend.push_back((*it)[0]);
	}
	S.insert(S.begin(), pend[0]);
	pend.erase(pend.begin());
	jacob_seq = PmergeMe::build_jacob_insertion_sequence(pend);

	unsigned int iterator = 1;
	unsigned int jacobindex = 3;
	std::vector<int> indexSeq;
	std::string last = "default";
	int item;
	std::list<int>::iterator insertion_point;

	while (iterator <= pend.size())
	{
		if (jacob_seq.size() != 0 && last != "jacob")
		{
			indexSeq.push_back(jacob_seq[0]);
			item = pend[jacob_seq[0] - 1];
			jacob_seq.erase(jacob_seq.begin());
			last = "jacob";
		}
		else
		{
			if (std::find(indexSeq.begin(), indexSeq.end(), iterator) != indexSeq.end())
				iterator++;
			item = pend[iterator - 1];
			indexSeq.push_back(iterator);
			last = "not-jacob";
		}
		insertion_point = PmergeMe::bisect(S, item);
		S.insert(insertion_point, item);
		iterator++;
		jacobindex++;
	}

	insertion_point = PmergeMe::bisect(S, straggler);
	S.insert(insertion_point, straggler);
	return (S);
}

std::list<int> PmergeMe::createS(std::list<std::vector<int> > sorted_split)
{
	std::list<int> S;
	std::vector<int> pend;
	std::vector<int> jacob_seq;

	for (std::list<std::vector<int> >::iterator it = sorted_split.begin(); it != sorted_split.end(); it++)
	{
		S.push_back((*it)[1]);
		pend.push_back((*it)[0]);
	}
	S.insert(S.begin(), pend[0]);
	pend.erase(pend.begin());
	jacob_seq = PmergeMe::build_jacob_insertion_sequence(pend);

	unsigned int iterator = 1;
	unsigned int jacobindex = 3;
	std::vector<int> indexSeq;
	std::string last = "default";
	int item;
	std::list<int>::iterator insertion_point;

	while (iterator <= pend.size())
	{
		if (jacob_seq.size() != 0 && last != "jacob")
		{
			indexSeq.push_back(jacob_seq[0]);
			item = pend[jacob_seq[0] - 1];
			jacob_seq.erase(jacob_seq.begin());
			last = "jacob";
		}
		else
		{
			if (std::find(indexSeq.begin(), indexSeq.end(), iterator) != indexSeq.end())
				iterator++;
			item = pend[iterator - 1];
			indexSeq.push_back(iterator);
			last = "not-jacob";
		}
		insertion_point = PmergeMe::bisect(S, item);
		S.insert(insertion_point, item);
		iterator++;
		jacobindex++;
	}

	return (S);
}

std::list<int>::iterator	PmergeMe::bisect(std::list<int>& A, int item)
{
	for (std::list<int>::iterator it = A.begin(); it != A.end(); it++)
	{
		if ((*it) > item)
			return (it);
	}
	return (A.end());
}

// Helpers

double	PmergeMe::getTime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

double	PmergeMe::getDelta(double time)
{
	return (PmergeMe::getTime() - time);
}

std::vector<int>	PmergeMe::parseAsVec(int ac, char **av)
{
	std::vector<int>	args;
	for (int i = 1; i < ac; ++i)
	{
		std::string arg = av[i];
		int val = std::atoi(arg.c_str());
		if (val < 0)
			throw (PmergeMe::InvalidArgumentException());
		args.push_back(val);
	}
	return (args);
}

std::list<int>	PmergeMe::parseAsList(int ac, char **av)
{
	std::list<int>	args;
	for (int i = 1; i < ac; ++i)
	{
		std::string arg = av[i];
		int val = std::atoi(arg.c_str());
		if (val < 0)
			throw (PmergeMe::InvalidArgumentException());
		args.push_back(val);
	}
	return (args);
}

bool	PmergeMe::checkInput(std::vector<int> A)
{
	std::set<int>	set;
	for (std::vector<int>::iterator it = A.begin(); it != A.end(); ++it)
	{
		int num = *it;
		if (set.find(num) != set.end())
			throw (PmergeMe::DuplicateValueException());
		set.insert(num);
	}
	return (true);
}

bool	PmergeMe::checkInput(std::list<int> A)
{
	std::set<int>	set;
	for (std::list<int>::iterator it = A.begin(); it != A.end(); ++it)
	{
		int num = *it;
		if (set.find(num) != set.end())
			throw (PmergeMe::DuplicateValueException());
		set.insert(num);
	}
	return (true);
}

void	PmergeMe::print_s(std::vector<int> S)
{
	std::cout << "[ ";
	for (unsigned int i = 0; i < S.size(); i++)
		std::cout << S[i] << " ";
	std::cout << "]" << std::endl;
}

void	PmergeMe::print_split(std::vector<std::vector<int> > S)
{
	std::cout << "std::vector: [";
	for (unsigned int i = 0; i < S.size(); i++)
	{
		std::cout << "[ ";
		for (unsigned int j = 0; j < S[i].size(); j++)
		{
			std::cout << S[i][j] << " ";
		}
		std::cout << "]";
	}
	std::cout << "]" << std::endl;
}

void	PmergeMe::print_s(std::list<int> S)
{
	std::cout << "std::list: [ ";
	for (std::list<int>::iterator it = S.begin(); it != S.end(); it++)
		std::cout << *it << " ";
	std::cout << "]" << std::endl;
}

void	PmergeMe::print_split(std::list<std::vector<int> > S)
{
	std::cout << "[";
	for (std::list<std::vector<int> >::iterator it = S.begin(); it != S.end(); it++)
	{
		std::cout << "[ ";
		for (unsigned int j = 0; j < (*it).size(); j++)
		{
			std::cout << (*it)[j] << " ";
		}
		std::cout << "]";
	}
	std::cout << "]" << std::endl;
}

int	PmergeMe::jacobstahl(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (PmergeMe::jacobstahl(n - 1) + 2 * PmergeMe::jacobstahl(n - 2));
}

std::vector<int> PmergeMe::build_jacob_insertion_sequence(std::vector<int> pend)
{
	int len = (int) pend.size();
	std::vector<int> end_seq;
	int jacob_index = 3;
	while (PmergeMe::jacobstahl(jacob_index) < len - 1)
	{
		end_seq.push_back(PmergeMe::jacobstahl(jacob_index));
		jacob_index++;
	}
	return (end_seq);
}
