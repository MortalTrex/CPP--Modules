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
	std::cout << m;
}

void Character::unequip(int idx)
{
	std::cout << idx;
}

void Character::use(int idx, ICharacter& target)
{
	std::cout << idx;
	std::cout << &target;
}