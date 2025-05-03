/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:24:01 by rbalazs           #+#    #+#             */
/*   Updated: 2025/05/03 20:24:02 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
    if (name.empty())
    {
        std::cerr << "Error: name is empty for HumanA" << std::endl;
        std::exit(1);
    }
    if (weapon.getType().empty())
    {
        std::cerr << "Error: weapon type is empty for HumanA" << std::endl;
        std::exit(1);
    }
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}