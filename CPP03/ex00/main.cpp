#include "ClapTrap.hpp"

int main ()
{
    ClapTrap claptrap;
    claptrap.attack("Bot");
    ClapTrap newclaptrap("Dollyne");
    newclaptrap.attack("Ralph");
    newclaptrap.takeDamage(5);
    claptrap.takeDamage(2);
    newclaptrap.beRepaired(5);
    claptrap.attack("Bot");
}