#include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0 ; i < 4 ; i++)
	{
		this->_materia[i] = NULL;
	}
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
	for (int i = 0 ; i < 4 ; i++)
	{
		if (_materia[i])
			delete _materia[i];
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (m)
	{
		for (int i = 0; i < 4; i++)
		{
			if (!_materia[i])
			{
				_materia[i] = m->clone();
				delete m;
				return ;
			}
		}
	}
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