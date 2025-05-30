#include "../inc/Animal.hpp"

Animal::Animal() : _type("Animal") {
    std::cout << "\033[32mAnimal default constructor called\033[0m" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type) {
    std::cout << "\033[32mAnimal copy constructor called\033[0m" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    std::cout << "\033[32mAnimal assignment operator called\033[0m" << std::endl;
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "\033[31mAnimal destructor called\033[0m" << std::endl;
}

std::string Animal::getType() const
{
    return this->_type;
}

void Animal::makeSound() const
{
    std::cout << "No Sound" << std::endl;
}
