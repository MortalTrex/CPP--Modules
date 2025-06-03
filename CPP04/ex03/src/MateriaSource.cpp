#include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource()
{

}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	*this = src; 
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0 ; i < 4 ; i++)
		{
			this->array[i] = other.array[i];
		}
	}
	return *this;
}

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