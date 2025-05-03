/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:24:48 by rbalazs           #+#    #+#             */
/*   Updated: 2025/05/03 20:34:07 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name)
{
	if (name.empty())
	{
		std::cerr << "Error: name is empty" << std::endl;
		return;
	}
	Zombie zombie(name);
	zombie.announce();
}