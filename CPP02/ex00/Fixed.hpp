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
        Fixed(const Fixed &copy);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        
        Fixed& operator=(const Fixed &copy);
    };


#endif