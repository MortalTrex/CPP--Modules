#include "../inc/Character.hpp"

Character::Character()
{

}

Character::Character(std::string const &name) : _name(name)
{

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
			_inventory[i] = m;
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
	std::cout << idx << " at " << &target << std::endl;
}