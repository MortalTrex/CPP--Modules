#include "../inc/AMateria.hpp"

AMateria::AMateria() : _type("Unknown")
{

}

AMateria::AMateria(std::string const &type) : _type(type)
{

}

AMateria::AMateria(const AMateria &src)
{
	this->_type = src._type;
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
	if (target.getName().empty())
	{
		std::cerr << "\033[31mUnknown target\033[0m" << std::endl;
		return;
	}
	std::cout << "\033[31m* uses unknown materia on " << target.getName() << " *\033[0m" << std::endl;
}
