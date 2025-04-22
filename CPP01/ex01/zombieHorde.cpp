#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombie;
	if (N < 0)
		std::cout << "Number inferior at 0" << std::endl;
	for (int i = 0 ; i < N ; i++)
	{
		zombie = new Zombie(name);
		zombie->announce();
		delete zombie;
	}
	return(zombie);
}