#include "../inc/Character.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->_name = other._name;
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		delete _inventory[i];
	}
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0 ; i < 4 ; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << i;
			return;
		}
	}
	std::cout << "Materia equipped" <<  std::endl;
}

void Character::unequip(int idx)
{
	std::cout << idx << std::endl;
	std::cout << "Materia " << idx << " unequipped" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (!_inventory[idx])
	{
		std::cout << target.getName() << " doesn't have a Materia on " << idx << " index."  << std::endl;
		return ;
	}
	if (idx < 0 || idx > 3)
	{
		std::cout << "Index is outside the range" << std::endl;
		return ;
	}
	_inventory[idx]->use(target);
}