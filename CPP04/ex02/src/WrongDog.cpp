#include "../inc/WrongDog.hpp"

WrongDog::WrongDog()
{
    _type = "WrongDog";
    _brain = new Brain();
    std::cout << "\033[31mWrongDog default constructor called\033[0m" << std::endl;
}

WrongDog::WrongDog(const WrongDog &other) : WrongAnimal(other)
{
    this->_brain = new Brain(*other._brain);
    this->_type = other._type;
    std::cout << "\033[31mWrongDog copy constructor called\033[0m" << std::endl;
}

WrongDog &WrongDog::operator=(const WrongDog &other)
{
    std::cout << "\033[31mWrongDog assignment operator called\033[0m" << std::endl;
    if (this != &other) {
        this->_type = other._type;
        *this->_brain = *other._brain;
    }
    return *this;
}

WrongDog::~WrongDog()
{
    delete _brain;
    std::cout << "\033[31mWrongDog destructor called\033[0m" << std::endl;
}

void WrongDog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}

void WrongDog::setIdea(int i, const std::string& newIdea)
{
    if (i < 0 || i > 99)
    {
        std::cout << "Index is outside the range" << std::endl;
        return;
    }
    this->_brain->setIdea(i, newIdea);
}

std::string WrongDog::getIdea(int i) const
{
    if (i < 0 || i > 99)
        return "Index is outside the range";
    if (this->_brain->getIdea(i).empty())
        return "No idea";
    return this->_brain->getIdea(i);
}