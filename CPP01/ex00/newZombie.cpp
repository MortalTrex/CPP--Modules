/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:24:46 by rbalazs           #+#    #+#             */
/*   Updated: 2025/05/03 20:24:47 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	if (name.empty())
	{
		std::cerr << "Error: name is empty" << std::endl;
		return (NULL);
	}
	Zombie *zombie = new Zombie(name);
	if (!zombie)
	{
		std::cerr << "Error: cannot allocate memory" << std::endl;
		return (NULL);
	}
	zombie->announce();
	return (zombie);
}