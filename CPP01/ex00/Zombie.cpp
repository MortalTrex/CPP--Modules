#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	name = name;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " is dead." << std::endl;
}