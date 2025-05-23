#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <string>


class Fixed
{
    private:
        int                 _fixedPoint;
        static const int    _nbBits;

    public: 
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &copy);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
        
        Fixed& operator=(const Fixed &copy);
    };
    std::ostream& operator<<(std::ostream &out, const Fixed &fixed);


#endif