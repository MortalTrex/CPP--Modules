# include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon()
{
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