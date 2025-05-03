/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:24:26 by rbalazs           #+#    #+#             */
/*   Updated: 2025/05/03 20:24:27 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *horde;
	int nb_zombies = 42;
	horde = zombieHorde(nb_zombies, "zombie");
	delete[] horde;
	horde = zombieHorde(0, "zombie");
	horde = zombieHorde(2147483646, "zombie");
	horde = zombieHorde(-2147483648, "zombie");
	horde = zombieHorde(5, "");
	return (0);
}