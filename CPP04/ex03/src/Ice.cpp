#include "../inc/Ice.hpp"

Ice::Ice() : AMateria("Ice")
{

}

Ice::Ice(std::string const &src) : AMateria(src)
{

}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
		this->AMateria::operator=(other);
	return *this;
}

Ice::~Ice()
{
	
}