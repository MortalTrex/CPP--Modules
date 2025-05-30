#include "../inc/Dog.hpp"

Dog::Dog()
{
    _type = "Dog";
    _brain = new Brain();
    std::cout << "\033[32mDog default constructor called\033[0m" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    _brain = new Brain();
    std::cout << "\033[32mDog copy constructor called\033[0m" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
    std::cout << "\033[32mDog assignment operator called\033[0m" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
        *this->_brain = *other._brain;
    }
    return *this;
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "\033[32mDog destructor called\033[0m" << std::endl;
}

void Dog::setIdea(int i, const std::string& newIdea) 
{
    this->_brain->setIdea(i, newIdea);
}

std::string Dog::getIdea(int i) const
{
    return this->_brain->getIdea(i);
}