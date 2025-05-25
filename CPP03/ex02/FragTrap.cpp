#include "FragTrap.hpp"

// Constructor and Destructor implementations

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "\033[31mFragTrap Constructor has been called\033[0m" << std::endl;
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "\033[31mFragTrap Parameterized Constructor Called!\033[0m" << std::endl;
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "\033[31mFragTrap Copy constructor has been called\033[0m" << std::endl;
	*this = other;
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
		ClapTrap::operator=(other);
		_HitPoints = other._HitPoints;
		_EnergyPoints = other._EnergyPoints;
		_AttackDamage = other._AttackDamage;
	}
	return *this;
}

// Functions


void FragTrap::highFivesGuys()
{
	if (_HitPoints == 0)
	{
		std::cout << "FragTrap is not alive" << std::endl;
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
}