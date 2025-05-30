#include "ScavTrap.hpp"

// Constructor and Destructor implementations

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "\033[31mScavTrap Constructor has been called\033[0m" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "\033[31mScavTrap Parameterized Constructor Called!\033[0m" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "\033[31mScavTrap Copy constructor has been called\033[0m" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "\033[31mScavTrap Destructor has been called\033[0m" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "\033[31mScavTrap Assignment Operator Called!\033[0m" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
    }
    return *this;
}

// Functions

void ScavTrap::attack(const std::string& target)
{
    if (target.empty())
    {
        std::cout << "ScavTrap cannot attack an empty target!" << std::endl;
        return;
    }
    if (_hitPoints == 0)
    {
        std::cout << "ScavTrap is not alive" << std::endl;
        return;
    }
    if (_energyPoints == 0)
    {
        std::cout << "ScavTrap has no energy left to attack!" << std::endl;
        return;
    }
    if (_name.empty())
    {
        std::cout << "ScavTrap" << " attacks " << target << " causing "
                  << _attackDamage << " points of damage! " << std::endl;
    }
    else
    {
        std::cout << "ScavTrap "
                  << _name << " attacks " << target << " causing "
                  << _attackDamage << " points of damage! " << std::endl;
    }
    _energyPoints--;
}

void ScavTrap::guardGate()
{
    if (_hitPoints == 0)
    {
        std::cout << "ScavTrap is not alive" << std::endl;
        return;
    }
    if (_energyPoints == 0)
    {
        std::cout << "ScavTrap doesn't have energy" << std::endl;
        return;
    }
    if (_name.empty())
    {
        std::cout << "ScavTrap is now in Gate Keeper mode!" << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode!" << std::endl;
    }
    _energyPoints--;
}