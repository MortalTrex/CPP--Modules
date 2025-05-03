/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:24:06 by rbalazs           #+#    #+#             */
/*   Updated: 2025/05/03 20:24:07 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon()
{
    if (name.empty())
    {
        std::cerr << "Error: name for HumanB is empty" << std::endl;
        std::exit(1);
    }
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}

void HumanB::attack()
{
    if (this->_weapon)
        std::cout << _name << " attacks with their " << this->_weapon->getType() << std::endl;
    else
        std::cout << _name << " doesn't have a weapon." << std::endl;
}