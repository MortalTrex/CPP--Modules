#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	std::cout << "Construction of ClapTrap" << std::endl;
	ClapTrap claptrap("ClapTrap");
	std::cout << "Construction of ScavTrap" << std::endl;
    ScavTrap scavtrap("ScavTrap");
	std::cout << "Construction of FragTrap" << std::endl;
	FragTrap fragtrap("FragTrap");

	std::cout << std::endl << "\033[32mINFOS OF FRAGTRAP\033[0m" << std::endl;
    std::cout << "\033[34mHitPoints: \033[0m" << fragtrap.getHitPoints() << std::endl;
    std::cout << "\033[34mEnergyPoints: \033[0m" << fragtrap.getEnergyPoints() << std::endl;
    std::cout << "\033[34mAttackDamage: \033[0m" << fragtrap.getAttackDamage() << std::endl;

	scavtrap.guardGate();

	claptrap.attack(scavtrap.getName());
	scavtrap.takeDamage(claptrap.getAttackDamage());

	scavtrap.attack(claptrap.getName());
	claptrap.takeDamage(scavtrap.getAttackDamage());

	fragtrap.highFivesGuys();

	scavtrap.attack(fragtrap.getName());
	fragtrap.takeDamage(100);
	fragtrap.highFivesGuys();

	fragtrap.attack(scavtrap.getName());
	scavtrap.takeDamage(fragtrap.getAttackDamage());
	
	
	claptrap.beRepaired(11);

	//Verification of informations after actions
	std::cout << std::endl << "\033[32mINFOS OF CLAPTRAP\033[0m" << std::endl;
    std::cout << "\033[34mHitPoints: \033[0m" << claptrap.getHitPoints() << std::endl;
    std::cout << "\033[34mEnergyPoints: \033[0m" << claptrap.getEnergyPoints() << std::endl;
    std::cout << "\033[34mAttackDamage: \033[0m" << claptrap.getAttackDamage() << std::endl;

    std::cout << std::endl << "\033[32mINFOS OF SCAVTRAP\033[0m" << std::endl;
    std::cout << "\033[34mHitPoints: \033[0m" << scavtrap.getHitPoints() << std::endl;
    std::cout << "\033[34mEnergyPoints: \033[0m" << scavtrap.getEnergyPoints() << std::endl;
    std::cout << "\033[34mAttackDamage: \033[0m" << scavtrap.getAttackDamage() << std::endl;

	std::cout << std::endl << "\033[32mINFOS OF FRAGTRAP\033[0m" << std::endl;
    std::cout << "\033[34mHitPoints: \033[0m" << fragtrap.getHitPoints() << std::endl;
    std::cout << "\033[34mEnergyPoints: \033[0m" << fragtrap.getEnergyPoints() << std::endl;
    std::cout << "\033[34mAttackDamage: \033[0m" << fragtrap.getAttackDamage() << std::endl;

    // Verification of copy
    std::cout << std::endl << "\033[32mINFOS OF NEW FRAGTRAP AFTER COPY\033[0m" << std::endl;
    FragTrap copyfragtrap(fragtrap);
    std::cout << "\033[34mHitPoints: \033[0m" << copyfragtrap.getHitPoints() << std::endl;
    std::cout << "\033[34mEnergyPoints: \033[0m" << copyfragtrap.getEnergyPoints() << std::endl;
    std::cout << "\033[34mAttackDamage: \033[0m" << copyfragtrap.getAttackDamage() << std::endl;
	return (0);
}