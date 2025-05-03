/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:24:35 by rbalazs           #+#    #+#             */
/*   Updated: 2025/05/03 20:24:36 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int verif_ZombieHorde(int N, std::string name)
{
	if (name.empty())
	{
		std::cerr << "Error : Name is empty" << std::endl;
		return (1);
	}
	if (N <= 0)
	{
		std::cerr << "Error : Number inferior or equal at 0" << std::endl;
		return (1);
	}
	if (N >= 10000)
	{
		std::cerr << "Error : You exceed the RAM" << std::endl;
		return (1);
	}
	return (0);
}

Zombie* zombieHorde( int N, std::string name )
{
	if (verif_ZombieHorde(N, name))
		return (NULL);
	Zombie *zombie;
	zombie = new Zombie[N];
	if (!zombie)
	{
		std::cerr << "Error: cannot allocate memory" << std::endl;
		return (NULL);
	}
	for (int i = 0 ; i < N ; i++)
	{
		zombie[i].setName_Number(name, i + 1);
		zombie[i].announce();
	}
	return(zombie);
}