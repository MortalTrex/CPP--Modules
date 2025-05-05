#include "Fixed.hpp"

Fixed::Fixed(){}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy called" << std::endl;
    if (this != &copy)
        this->_nbBits = copy.getRawBits();
    return *this;
}

Fixed& Fixed::operator=(const Fixed &copy)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &copy)
        this->_nbBits = copy.getRawBits();
    return *this;
}

Fixed::~Fixed(){}

int getRawBits(void) const
{
    std::cout << "getRawBits called" << std::endl;
    return this->_value;
}

void setRawBits(int const raw)


