#include "../inc/WrongDog.hpp"

WrongDog::WrongDog()
{
    _type = "WrongDog";
    std::cout << "WrongDog default constructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog &other) : WrongAnimal(other) {
    std::cout << "WrongDog copy constructor called" << std::endl;
}

WrongDog &WrongDog::operator=(const WrongDog &other) {
    std::cout << "WrongDog assignment operator called" << std::endl;
    WrongAnimal::operator=(other);
    return *this;
}

WrongDog::~WrongDog() {
    std::cout << "WrongDog destructor called" << std::endl;
}