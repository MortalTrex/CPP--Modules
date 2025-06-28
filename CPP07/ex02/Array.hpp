#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdlib.h>
#include "Array.tpp"

template<typename T>
class Array
{
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &copy);
        ~Array();
        Array &operator=(const Array &copy);
        T &operator[]( unsigned int index );
        
};

#endif
