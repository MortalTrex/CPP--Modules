#include "../inc/MateriaSource.hpp"

MateriaSource::~MateriaSource()
{

}

void MateriaSource::learnMateria(AMateria*)
{
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	std::cout << type;
	return NULL;
}