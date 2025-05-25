#include "ClapTrap.hpp"

// Constructor and Destructor implementations

ClapTrap::ClapTrap() : _name(""), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
    std::cout << "\033[31mConstructor has been called\033[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
    std::cout << "\033[31mClapTrap Parameterized Constructor Called!\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "\033[31mCopy constructor has been called\033[0m" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "\033[31mClapTrap Assignment Operator Called!\033[0m" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _HitPoints = other._HitPoints;
        _EnergyPoints = other._EnergyPoints;
        _AttackDamage = other._AttackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "\033[31mDestructor has been called\033[0m" << std::endl;
}


// Getters

std::string ClapTrap::getName() const
{
    return _name;
}
unsigned int ClapTrap::getHitPoints() const
{
    return _HitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
    return _EnergyPoints;
}

unsigned int ClapTrap::getAttackDamage() const
{
    return _AttackDamage;
}



// Member function implementations

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
    if(_name.empty()){
        std::cout << "ClapTrap" << " attacks " << target << " causing "
                << _AttackDamage << " points of damage! " << std::endl;
    }
    else{
        std::cout << "ClapTrap "
                << _name << " attacks " << target << " causing "
                << _AttackDamage << " points of damage! " << std::endl;
    }
    _EnergyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_HitPoints == 0)
    {
        std::cout << "Claptrap is not alive" << std::endl;
        return;
    }
    if (_name.empty())
    {
        std::cout << "ClapTrap" << " has taken " << amount << " damage :( "
            << std::endl;
    }
    else
    {
        std::cout << "ClapTrap "
            << _name << " has taken " << amount << " damage :( "
            << std::endl;
    }
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
        if (_name.empty())
        {
            std::cout << "ClapTrap" << " is repaired with " << amount << " hit points "
                << std::endl;
        }
        else
        {
            std::cout << "ClapTrap "
                    << _name << " is repaired with " << amount << " hit points "
                    << std::endl;
        }
        _HitPoints += amount;
        _EnergyPoints--;
    }
    else
    {
        std::cout << "Not enough energy points" << std::endl;
    }
}

