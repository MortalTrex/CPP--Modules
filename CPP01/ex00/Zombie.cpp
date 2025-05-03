/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:24:51 by rbalazs           #+#    #+#             */
/*   Updated: 2025/05/03 20:24:52 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "\033[32mConstructor called\033[0m" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "\033[31m" << this->_name << " is died due to the destructor\033[0m" << std::endl;
}