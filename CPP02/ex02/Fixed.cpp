#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
}

Fixed::Fixed(const int value)
{
    this->_rawBits = value << this->_nbBits;
}

Fixed::Fixed(const float value)
{
    this->_rawBits = roundf(value * (1 << this->_nbBits));
}

Fixed::Fixed(const Fixed &copy)
{
    if (this != &copy)
        *this = copy;
}

Fixed& Fixed::operator=(const Fixed &copy)
{
    if (this != &copy)
        this->_rawBits = copy.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
    return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
    this->_rawBits = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)this->_rawBits / (1 << this->_nbBits));
}

int Fixed::toInt(void) const
{
    return (this->_rawBits >> this->_nbBits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}


// Overload the max and min functions

Fixed &	Fixed::min( Fixed & a, Fixed & b )
{
	if ( a.toFloat() <= b.toFloat())
		return ( a );
	return ( b );
}

const Fixed &	Fixed::min(Fixed const & a, Fixed const & b)
{
	if ( a.toFloat() <= b.toFloat())
		return ( a );
	return ( b );
}
Fixed &	Fixed::max( Fixed & a, Fixed & b )
{
	if ( a.toFloat() >= b.toFloat())
		return ( a );
	return ( b );
}
const Fixed &	Fixed::max( Fixed const & a, Fixed const & b )
{
	if ( a.toFloat() >= b.toFloat())
		return ( a );
	return ( b );
}

// Overload the comparison operators

bool Fixed::operator>(const Fixed &other) const
{
    return this->_rawBits > other._rawBits;
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->_rawBits < other._rawBits;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->_rawBits >= other._rawBits;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->_rawBits <= other._rawBits;
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->_rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->_rawBits != other._rawBits;
}

// Overload the arithmetic operators

Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    if (other.getRawBits() == 0)
    {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / other.toFloat());
}

// Overload the increment and decrement operators

Fixed& Fixed::operator++()
{
    this->_rawBits++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->_rawBits++;
    return temp;
}

Fixed& Fixed::operator--()
{
    this->_rawBits--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->_rawBits--;
    return temp;
}
