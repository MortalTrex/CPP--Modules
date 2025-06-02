#include "../inc/AMateria.hpp"

AMateria::AMateria()
{

}

AMateria::AMateria(std::string const &type) : _type(type)
{

}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

AMateria::~AMateria()
{
	
}