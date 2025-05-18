#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "\033[31mConstructor has been called\033[0m" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "\033[31mDestructor has been called\033[0m" << std::endl;
}