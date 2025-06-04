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

void AMateria::setType(std::string const &type)
{
	this->_type = type;
}

void AMateria::use(ICharacter& target)
{
	if (this->_type == "Ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (this->_type == "Cure")
		std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	else
		std::cout << "* uses unknown materia on " << target.getName() << " *" << std::endl;
}

