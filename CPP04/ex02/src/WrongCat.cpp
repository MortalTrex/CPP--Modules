#include "../inc/WrongCat.hpp"

WrongCat::WrongCat() 
{
    _type = "WrongCat";
    _brain = new Brain();
    std::cout << "\033[31mWrongCat default constructor called\033[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    this->_brain = new Brain(*other._brain);
    this->_type = other._type;
    std::cout << "\033[31mWrongCat copy constructor called\033[0m" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "\033[31mWrongCat assignment operator called\033[0m" << std::endl;
    if (this != &other) {
        this->_type = other._type;
        *this->_brain = *other._brain;
    }
    return *this;
}

WrongCat::~WrongCat()
{
    delete _brain;
    std::cout << "\033[31mWrongCat destructor called\033[0m" << std::endl;
}


void WrongCat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}

void WrongCat::setIdea(int i, const std::string& newIdea)
{
    if (i < 0 || i > 99)
    {
        std::cout << "Index is outside the range" << std::endl;
        return;
    }
    this->_brain->setIdea(i, newIdea);
}

std::string WrongCat::getIdea(int i) const
{
    if (i < 0 || i > 99)
        return "Index is outside the range";
    if (this->_brain->getIdea(i).empty())
        return "No idea";
    return this->_brain->getIdea(i);
}
