#include "FragTrap.hpp"

// Constructor and Destructor implementations

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "\033[31mFragTrap Constructor has been called\033[0m" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "\033[31mFragTrap Parameterized Constructor Called!\033[0m" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
	std::cout << "\033[31mFragTrap Copy Constructor has been called\033[0m" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "\033[31mFragTrap Destructor has been called\033[0m" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "\033[31mFragTrap Assignment Operator Called!\033[0m" << std::endl;
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

void FragTrap::highFivesGuys()
{
	if (_hitPoints == 0)
	{
		std::cout << "FragTrap is not alive" << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "FragTrap doesn't have energy" << std::endl;
		return;
	}
	if (_name.empty())
	{
		std::cout << "FragTrap requests a high five!" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
	}
	_energyPoints--;
}