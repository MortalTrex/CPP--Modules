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
			delete this->_materia[i];
			if (other._materia[i])
				this->_materia[i] = other._materia[i]->clone();
			else
				this->_materia[i] = NULL;
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
		std::cerr << "\033[31mInventory full, cannot learn more materia\033[0m" << std::endl;
		delete m;
		return ;
	}
	std::cerr << "\033[31mCannot learn this materia\033[0m" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	if (type.empty())
	{
		std::cerr << "\033[31mCannot create materia with empty type\033[0m" << std::endl;
		return NULL;
	}
	for (int i = 0; i < 4 ; i++)
	{
		if (_materia[i] && _materia[i]->getType() == type)
			return _materia[i]->clone();
	}
	std::cerr << "\033[31mMateria of type " << type << " not found\033[0m" << std::endl;
	return NULL;
}