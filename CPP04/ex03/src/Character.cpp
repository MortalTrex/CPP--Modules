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
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}


Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (m)
	{
		for (int i = 0 ; i < 4 ; i++)
		{
			if (!_inventory[i])
			{
				_inventory[i] = m;
				std::cout << _inventory[i] << std::endl;
				std::cout << "Materia equipped" <<  std::endl;
				return;
			}
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Index is outside the range" << std::endl;
		return ;
	}
	if (!_inventory[idx])
	{
		std::cout << "doesn't have a Materia on " << idx << " index."  << std::endl;
		return ;
	}
	std::cout << "  " << std::endl;
	//_inventory[idx] = NULL;
	std::cout << "Materia " << idx << " unequipped" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Index is outside the range" << std::endl;
		return ;
	}
	if (!_inventory[idx])
	{
		std::cout << target.getName() << " doesn't have a Materia on " << idx << " index."  << std::endl;
		return ;
	}
	_inventory[idx]->use(target);
}