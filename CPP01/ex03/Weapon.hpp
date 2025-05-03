/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:24:17 by rbalazs           #+#    #+#             */
/*   Updated: 2025/05/03 20:24:18 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>
#include <cstdlib>

class Weapon
{
	private:
		std::string type;

	public:
		Weapon(std::string type);
		~Weapon();
		void setType(std::string type);
		std::string getType(void) const;
};

#endif
