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
		for (int i = 0; i < 4; i++)
		{
			delete this->_inventory[i];
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
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
	for (size_t i = 0; i < _trashinventory.size(); i++)
	{
		if (_trashinventory[i])
			delete _trashinventory[i];
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
				std::cout << "Materia " << m->getType() << " equipped on index " << i << std::endl;
				return;
			}
		}
		std::cout << "\033[31mNo more place in inventory\033[0m" << std::endl;
		delete m;
		return;
	}
	std::cout << "\033[31mMateria doesn't exist.\033[0m" << std::endl;
	return;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "\033[31mIndex is outside the range\033[0m" << std::endl;
		return ;
	}
	if (!_inventory[idx])
	{
		std::cout << "\033[31m" << this->getName() << " doesn't have a Materia on " << idx << " index.\033[0m" << std::endl;
		return ;
	}
	_trashinventory.push_back(_inventory[idx]);
	_inventory[idx] = NULL;
	std::cout << "Materia " << idx << " unequipped" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "\033[31mIndex is outside the range\033[0m" << std::endl;
		return ;
	}
	if (!_inventory[idx])
	{
		std::cout << "\033[31m" << this->getName() << " doesn't have a Materia on " << idx << " index.\033[0m" << std::endl;
		return ;
	}
	_inventory[idx]->use(target);
}