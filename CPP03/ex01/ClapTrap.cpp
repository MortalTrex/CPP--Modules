#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
    std::cout << "\033[31mConstructor has been called\033[0m" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "\033[31mDestructor has been called\033[0m" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (target.empty())
    {
        std::cout << "No target specified." << std::endl;
        return;
    }
    if (_HitPoints == 0)
    {
        std::cout << "Claptrap is not alive" << std::endl;
        return;
    }
    if (_EnergyPoints == 0)
    {
        std::cout << "Not enough energy" << std::endl;
        return;
    }

    std::cout << "ClapTrap"
            << _name << " attacks " << target << " causing "
            << _AttackDamage << " points of damage! " << std::endl;
    _EnergyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_HitPoints == 0)
    {
        std::cout << "Claptrap is not alive" << std::endl;
        return;
    }
    std::cout << "ClapTrap"
            << _name << " has taken " << amount << " damage :( "
            << std::endl;
    for(unsigned int i = 0 ; i < amount ; i++)
    {
        if (_HitPoints == 0)
            break;
        _HitPoints = _HitPoints - 1;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_HitPoints == 0)
    {
        std::cout << "Claptrap is not alive" << std::endl;
        return;
    }
    if (_EnergyPoints > 0)
    {
        std::cout << "ClapTrap"
                << _name << " is repaired with " << amount << " hit points "
                << std::endl;
        _HitPoints += amount;
        _EnergyPoints--;
    }
    else
    {
        std::cout << "Not enough energy points" << std::endl;
    }
}

