#include "../inc/AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
    std::cout << "\033[32mAnimal default constructor called\033[0m" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : _type(other._type) {
    std::cout << "\033[32mAnimal copy constructor called\033[0m" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
    std::cout << "\033[32mAnimal assignment operator called\033[0m" << std::endl;
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "\033[31mAnimal destructor called\033[0m" << std::endl;
}

std::string AAnimal::getType() const
{
    return this->_type;
}

void AAnimal::makeSound() const
{
    std::cout << "No Sound" << std::endl;
}
