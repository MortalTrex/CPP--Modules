#include "Fixed.hpp"

const int Fixed::_nbBits = 8;

Fixed::Fixed() : _fixedPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPoint = value << this->_nbBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPoint = roundf(value * 256);
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

float Fixed::toFloat(void) const
{
    return ((float)this->_fixedPoint / 256);
}

int Fixed::toInt(void) const
{
    return (this->_fixedPoint >> this->_nbBits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}
