/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:24:32 by rbalazs           #+#    #+#             */
/*   Updated: 2025/05/03 20:24:33 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string _name;
	int _number;

public:
	Zombie();
	~Zombie();
	void announce();
	void setName_Number(std::string name, int number);
};
Zombie* zombieHorde( int N, std::string name );

#endif