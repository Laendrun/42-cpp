/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:46:53 by saeby             #+#    #+#             */
/*   Updated: 2023/02/17 21:15:46 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string	read_file(std::ifstream& file)
{
	std::string	tmp;
	char		c;

	while (file.get(c))
		tmp += c;
	return tmp;
}

std::string	search_replace(std::string str, std::string orig, std::string goal)
{
	std::string	replaced_string;
	size_t		curr_pos;
	size_t		prev_pos;

	prev_pos = 0;
	curr_pos = 0;
	curr_pos = str.find(orig, curr_pos);
	while (curr_pos != std::string::npos)
	{
		while (prev_pos < curr_pos)
			replaced_string += str[prev_pos++];
		replaced_string += goal;
		curr_pos += orig.length();
		prev_pos = curr_pos;
		curr_pos = str.find(orig, curr_pos);
	}
	replaced_string += str[prev_pos];
	return (replaced_string);
}

int	main(int ac, char **av)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		outfile_name;
	std::string		if_content;
	if (ac != 4)
	{
		std::cout << "Wrong number of argument !" << std::endl;
		std::cout << "Usage:" << " ./sed <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	infile.open(av[1]);
	if (infile.fail())
	{
		std::cout << "Unable to open the file:" << " " << av[1] << std::endl;
		return (1);
	}
	outfile_name = av[1] + (std::string)".replace";
	outfile.open(outfile_name);

	if_content = read_file(infile);
	outfile << search_replace(if_content, av[2], av[3]);

	infile.close();
	outfile.close();
	return (0);
}
