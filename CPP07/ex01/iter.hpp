#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T>
void func (T a)
{
    a++;
    std::cout << "a = " << a << std::endl;
}

template <typename T, typename LEN, typename F>
void iter(T *array, LEN length, F func)
{
    for (LEN i = 0 ; i < length ; i++)
    {
        func(array[i]);
    }
}
#endif