#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (_type);
}

void WrongAnimal::makeSound() const
{
    if (_type == "WrongAnimal")
        std::cout << "No sound" << std::endl;
    else if (_type == "Dog")
        std::cout << "Woof!" << std::endl;
    else if (_type == "Cat")
        std::cout << "Meow!" << std::endl;
}