#include "../inc/Dog.hpp"

Dog::Dog()
{
    _type = "Dog";
    _brain = new Brain();
    std::cout << "\033[32mDog default constructor called\033[0m" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    this->_brain = new Brain(*other._brain);
    this->_type = other._type;
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
    std::cout << "\033[31mDog destructor called\033[0m" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof !" << std::endl;
}

void Dog::setIdea(int i, const std::string& newIdea) 
{
    if (i < 0 || i > 99)
    {
        std::cout << "Index is outside the range" << std::endl;
        return ;
    }
    this->_brain->setIdea(i, newIdea);
}

std::string Dog::getIdea(int i) const
{
    if (i < 0 || i > 99)
        return "Index is outside the range";
    if (this->_brain->getIdea(i).empty())
        return "No idea";
    return this->_brain->getIdea(i);
}