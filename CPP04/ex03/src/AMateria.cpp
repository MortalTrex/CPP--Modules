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

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	if (this->_type = "Ice")


}