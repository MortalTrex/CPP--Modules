#include "ClapTrap.hpp"

int main ()
{
    ClapTrap claptrap;
    ClapTrap newclaptrap("NewBot");

    claptrap.attack(newclaptrap.getName());
    newclaptrap.takeDamage(claptrap.getAttackDamage());
    claptrap.beRepaired(5);

    //Verification of death
    std::cout << std::endl;
    std::cout << "\033[34mHitPoints: \033[0m" << claptrap.getHitPoints() << std::endl;
    claptrap.takeDamage(12);
    std::cout << "\033[34mHitPoints: \033[0m" << claptrap.getHitPoints() << std::endl;
    claptrap.takeDamage(4);
    claptrap.takeDamage(4);
    claptrap.beRepaired(5);
    claptrap.attack("Bot");

    //Verification of information after actions
    std::cout << std::endl << "\033[32mINFOS OF CLAPTRAP\033[0m" << std::endl;
    std::cout << "\033[34mHitPoints: \033[0m" << claptrap.getHitPoints() << std::endl;
    std::cout << "\033[34mEnergyPoints: \033[0m" << claptrap.getEnergyPoints() << std::endl;
    std::cout << "\033[34mAttackDamage: \033[0m" << claptrap.getAttackDamage() << std::endl;

    std::cout << std::endl << "\033[32mINFOS OF NEWCLAPTRAP\033[0m" << std::endl;
    std::cout << "\033[34mHitPoints: \033[0m" << newclaptrap.getHitPoints() << std::endl;
    std::cout << "\033[34mEnergyPoints: \033[0m" << newclaptrap.getEnergyPoints() << std::endl;
    std::cout << "\033[34mAttackDamage: \033[0m" << newclaptrap.getAttackDamage() << std::endl;

    //Verification of copy constructor
    claptrap = newclaptrap;
    std::cout << std::endl << "\033[32mINFOS OF CLAPTRAP AFTER ASSIGNMENT\033[0m" << std::endl;
    std::cout << "\033[34mHitPoints: \033[0m" << claptrap.getHitPoints() << std::endl;
    std::cout << "\033[34mEnergyPoints: \033[0m" << claptrap.getEnergyPoints() << std::endl;
    std::cout << "\033[34mAttackDamage: \033[0m" << claptrap.getAttackDamage() << std::endl;

}