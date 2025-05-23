#include "Fixed.hpp"

const int Fixed::_nbBits = 8;

Fixed::Fixed() : _fixedPoint(0)
{
}

Fixed::Fixed(const int value)
{
    this->_fixedPoint = value << this->_nbBits;
}

Fixed::Fixed(const float value)
{
    this->_fixedPoint = roundf(value * 256);
}

Fixed::Fixed(const Fixed &copy)
{
    this->_fixedPoint = copy._fixedPoint;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
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

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    if (this != &copy)
        this->_fixedPoint = copy.getRawBits();
    return (*this);
}

// Overload the max and min functions

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.toFloat() <= b.toFloat())
        return (a);
    return (b);
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
    if (a.toFloat() <= b.toFloat())
        return (a);
    return (b);
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.toFloat() >= b.toFloat())
        return (a);
    return (b);
}
const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
    if (a.toFloat() >= b.toFloat())
        return (a);
    return (b);
}

// Overload the comparison operators

bool Fixed::operator>(const Fixed &other) const
{
    return (this->_fixedPoint > other._fixedPoint);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->_fixedPoint < other._fixedPoint);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->_fixedPoint >= other._fixedPoint);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->_fixedPoint <= other._fixedPoint);
}

bool Fixed::operator==(const Fixed &other) const
{
    return (this->_fixedPoint == other._fixedPoint);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (this->_fixedPoint != other._fixedPoint);
}

// Overload the arithmetic operators

Fixed Fixed::operator+(const Fixed &other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return (Fixed(toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
    if (other.getRawBits() == 0)
    {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed(0);
    }
    return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed &Fixed::operator++()
{
    this->_fixedPoint++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->_fixedPoint++;
    return (temp);
}

Fixed &Fixed::operator--()
{
    this->_fixedPoint--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->_fixedPoint--;
    return (temp);
}
