/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:24:15 by rbalazs           #+#    #+#             */
/*   Updated: 2025/05/03 20:46:09 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
    if (type.empty())
    {
        std::cerr << "Error: type is empty" << std::endl;
        std::exit(1);
    }
}

Weapon::~Weapon()
{
}

std::string Weapon::getType() const
{
    return (this->_type);
}

void Weapon::setType(std::string type)
{
    if (type.empty())
    {
        std::cerr << "Error: type is empty" << std::endl;
        std::exit(1);
    }
    this->_type = type;
}