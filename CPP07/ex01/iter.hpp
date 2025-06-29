#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

void func (int value)
{
    value++;
    std::cout << "value = " << value << std::endl;
}

template <typename T, typename Len, typename F>
void iter(T *array, Len length, F func)
{
    for (Len i = 0 ; i < length ; i++)
    {
        func(array[i]);
    }
}

#endif