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

Cure *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	if (target.getName().empty())
	{
		std::cerr << "\033[31mUnknown target\033[0m" << std::endl;
		return;
	}
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

