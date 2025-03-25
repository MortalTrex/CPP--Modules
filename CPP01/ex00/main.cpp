#include "Zombie.hpp"

void announce ( void )
{
	std::cout << "Braiiiiiiinnnssss..." << std::endl;
}

int main(void)
{
	Zombie*	zombie;

	//zombie = newZombie("Zombie1");
	zombie->announce();

	return (0);
}