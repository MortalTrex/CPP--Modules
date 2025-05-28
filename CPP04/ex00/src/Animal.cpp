#include "../inc/Animal.hpp"

Animal::Animal() : _type("Animal") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return this->_type;
}

void Animal::makeSound() const
{
    if (_type == "Dog")
        std::cout << "Woof !" << std::endl;
    else if (_type == "Cat")
        std::cout << "Meow !" << std::endl;
    else
        std::cout << "No Sound" << std::endl;
}