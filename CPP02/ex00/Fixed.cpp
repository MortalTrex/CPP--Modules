#include "Fixed.hpp"

const int Fixed::_nbBits = 8;

Fixed::Fixed() : _fixedPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_fixedPoint = copy._fixedPoint;
}


Fixed& Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->_fixedPoint = copy.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPoint = raw;
}



