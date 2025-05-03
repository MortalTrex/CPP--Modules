#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie;
	
	zombie = newZombie("Zombie");
	delete zombie;
	randomChump("Foo");
	return (0);
}