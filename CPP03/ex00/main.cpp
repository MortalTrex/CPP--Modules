#include "ClapTrap.hpp"

int main ()
{
    ClapTrap ClapTrap;
    ClapTrap.attack("Bot");
    ClapTrap.takeDamage(12);
    ClapTrap.takeDamage(2);
    ClapTrap.beRepaired(5);
    ClapTrap.attack("Bot");
}