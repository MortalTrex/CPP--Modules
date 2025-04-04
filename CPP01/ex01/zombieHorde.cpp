#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombie;
	for (int i = 0 ; i < N ; i++)
	{
		zombie = new Zombie(name);
	}
	return(zombie);
}