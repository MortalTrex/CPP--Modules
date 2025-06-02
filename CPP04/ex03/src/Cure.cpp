#include "../inc/Cure.hpp"

Cure::Cure() : AMateria("Cure")
{

}

Cure::Cure(std::string const &src) : AMateria(src)
{

}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
		this->AMateria::operator=(other);
	return *this;
}

Cure::~Cure()
{
	
}