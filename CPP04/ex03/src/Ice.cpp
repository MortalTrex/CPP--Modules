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

Ice *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	if (target.getName().empty())
	{
		std::cerr << "\033[31mUnknown target\033[0m" << std::endl;
		return;
	}
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

