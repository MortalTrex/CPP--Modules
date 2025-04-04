#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie;
	std::string foo = "Foo";

	zombie = newZombie("Zombie");
	zombie->announce();

	randomChump(foo);
	delete zombie;
	return (0);
}