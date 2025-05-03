/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:23:53 by rbalazs           #+#    #+#             */
/*   Updated: 2025/05/03 20:23:54 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void ft_replace(std::string filename, std::string s1, std::string s2)
{
	size_t 			pos;
	std::string 	line;
	std::ifstream	file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: cannot open " << filename << std::endl;
		return ;
	}
	std::ofstream 	newfile("newfile.txt");
	if (!newfile)
	{
		std::cerr << "Error: cannot create new file " << std::endl;
		return ;
	}
	while(std::getline(file, line))
	{
		pos = line.find(s1);
		while (pos != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos = line.find(s1);
		}
		newfile << line << std::endl;
	}
}