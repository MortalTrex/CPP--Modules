/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:24:29 by rbalazs           #+#    #+#             */
/*   Updated: 2025/05/03 20:24:30 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce()
{
	std::cout << this->_name << " number " << this->_number << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName_Number(std::string name, int number)
{
	this->_name = name;
	this->_number = number;
}

Zombie::Zombie()
{
	std::cout << "\033[32mConstructor called\033[0m" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "\033[31m" << this->_name << " number " 
		<< this->_number << " is died due to the destructor.\033[0m" << std::endl;
}