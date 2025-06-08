#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout << "\033[31mWrongAnimal default constructor called\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type)
{
    std::cout << "\033[31mWrongAnimal copy constructor called\033[0m" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "\033[31mWrongAnimal assignment operator called\033[0m" << std::endl;
    if (this != &other) {
        this->_type = other._type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "\033[31mWrongAnimal destructor called\033[0m" << std::endl;
}


std::string WrongAnimal::getType() const
{
    return (_type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "No sound" << std::endl;
}