#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdlib.h>

template<typename T>
class Array 
{
    private:
        T* _array;
        size_t _size;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &src);
        Array &operator=(const Array &copy);
        ~Array();

        T &operator[](size_t index);
        const T &operator[](size_t index) const;
        size_t size() const;
};

#include "Array.tpp"
#endif
