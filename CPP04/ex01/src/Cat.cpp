#include "../inc/Cat.hpp"

Cat::Cat() 
{
    _type = "Cat";
    _brain = new Brain();
    std::cout << "\033[32mCat default constructor called\033[0m" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    _brain = new Brain();
    std::cout << "\033[32mCat copy constructor called\033[0m" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "\033[32mCat assignment operator called\033[0m" << std::endl;
    if (this != &other)
    {
        _type = other._type;
        *this->_brain = *other._brain;
    }
    return *this;
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "\033[32mCat destructor called\033[0m" << std::endl;
}


void Cat::setIdea(int i, const std::string& newIdea) 
{
    this->_brain->setIdea(i, newIdea);
}

std::string Cat::getIdea(int i) const
{
    return this->_brain->getIdea(i);
}