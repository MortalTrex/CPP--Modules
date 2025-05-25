#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main ()
{
    ClapTrap claptrap;
    ScavTrap scavtrap("NewBot");

    claptrap.attack(scavtrap.getName());
    scavtrap.takeDamage(claptrap.getAttackDamage());
    claptrap.beRepaired(5);


    //Verification of information after actions
    std::cout << std::endl << "\033[32mINFOS OF CLAPTRAP\033[0m" << std::endl;
    std::cout << "\033[34mHitPoints: \033[0m" << claptrap.getHitPoints() << std::endl;
    std::cout << "\033[34mEnergyPoints: \033[0m" << claptrap.getEnergyPoints() << std::endl;
    std::cout << "\033[34mAttackDamage: \033[0m" << claptrap.getAttackDamage() << std::endl;

    std::cout << std::endl << "\033[32mINFOS OF scavtrap\033[0m" << std::endl;
    std::cout << "\033[34mHitPoints: \033[0m" << scavtrap.getHitPoints() << std::endl;
    std::cout << "\033[34mEnergyPoints: \033[0m" << scavtrap.getEnergyPoints() << std::endl;
    std::cout << "\033[34mAttackDamage: \033[0m" << scavtrap.getAttackDamage() << std::endl;
}