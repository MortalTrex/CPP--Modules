#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main ()
{
    ClapTrap claptrap("ClapTrap");
    ScavTrap scavtrap;

    std::cout << std::endl << "\033[32mINFOS OF SCAVTRAP\033[0m" << std::endl;
    std::cout << "\033[34mHitPoints: \033[0m" << scavtrap.getHitPoints() << std::endl;
    std::cout << "\033[34mEnergyPoints: \033[0m" << scavtrap.getEnergyPoints() << std::endl;
    std::cout << "\033[34mAttackDamage: \033[0m" << scavtrap.getAttackDamage() << std::endl;

    scavtrap.attack(claptrap.getName());
    claptrap.takeDamage(scavtrap.getAttackDamage());
    scavtrap.beRepaired(5);
    scavtrap.guardGate();

    claptrap.takeDamage(scavtrap.getAttackDamage());

    //Verification of information after actions
    std::cout << std::endl << "\033[32mINFOS OF CLAPTRAP\033[0m" << std::endl;
    std::cout << "\033[34mHitPoints: \033[0m" << claptrap.getHitPoints() << std::endl;
    std::cout << "\033[34mEnergyPoints: \033[0m" << claptrap.getEnergyPoints() << std::endl;
    std::cout << "\033[34mAttackDamage: \033[0m" << claptrap.getAttackDamage() << std::endl;

    std::cout << std::endl << "\033[32mINFOS OF SCAVTRAP\033[0m" << std::endl;
    std::cout << "\033[34mHitPoints: \033[0m" << scavtrap.getHitPoints() << std::endl;
    std::cout << "\033[34mEnergyPoints: \033[0m" << scavtrap.getEnergyPoints() << std::endl;
    std::cout << "\033[34mAttackDamage: \033[0m" << scavtrap.getAttackDamage() << std::endl;

    // Verification of copy
    std::cout << std::endl << "\033[32mINFOS OF NEW FRAGTRAP AFTER COPY\033[0m" << std::endl;
    ScavTrap copyscavtrap(scavtrap);
    std::cout << "\033[34mHitPoints: \033[0m" << copyscavtrap.getHitPoints() << std::endl;
    std::cout << "\033[34mEnergyPoints: \033[0m" << copyscavtrap.getEnergyPoints() << std::endl;
    std::cout << "\033[34mAttackDamage: \033[0m" << copyscavtrap.getAttackDamage() << std::endl;
	return (0);
}