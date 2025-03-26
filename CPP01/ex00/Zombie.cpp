#include "Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
	std::cout << name << ": ";
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " is dead." << std::endl;
}