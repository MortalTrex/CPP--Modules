#include "../inc/Brain.hpp"

Brain::Brain()
{
	std::cout << "\033[32mBrain default constructor called\033[0m" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "\033[32mBrain copy constructor called\033[0m" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = other._ideas[i];
	}
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "\033[32mBrain assignment operator called\033[0m" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "\033[31mBrain destructor called\033[0m" << std::endl;
}

void Brain::setIdea(int i, const std::string &newIdea)
{
	if (i < 0 || i > 99)
	{
		std::cout << "\033[31mError : Index is outside the array\033[0m" << std::endl;
		return;
	}
	this->_ideas[i] = newIdea;
}

std::string Brain::getIdea(int i) const
{
	if (i < 0 || i > 99)
	{
		std::cout << "\033[31mError : Index is outside the array\033[0m" << std::endl;
		return (NULL);
	}
	return (_ideas[i]);
}


