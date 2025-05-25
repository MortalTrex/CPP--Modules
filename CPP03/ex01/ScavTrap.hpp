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
        // Canonical Form
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& other);
        ~ScavTrap();

        // Functions
        void attack(const std::string& target);
        void guardGate();
};

#endif