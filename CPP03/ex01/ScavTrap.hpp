#ifndef SCAPTRAP_HPP
#define SCAPTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
    private :
        std::string _name;
        int _HitPoints;
        int _EnergyPoints;
        int _AttackDamage;

    public :
        ScavTrap();
        ScavTrap(std::string name);
        ~ScavTrap();
        void attack(const std::string& target);
        void guardGate();
};

#endif