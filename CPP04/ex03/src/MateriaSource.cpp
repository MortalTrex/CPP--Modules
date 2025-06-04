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
			this->_materia[i] = other._materia[i];
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
	for (int i = 0; i < 4 ; i++)
	{
		if (_materia[i] && _materia[i]->getType() == type)
			return _materia[i]->clone();
	}
	return NULL;
}