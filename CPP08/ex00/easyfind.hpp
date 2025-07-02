#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

template<typename T>
void easyfind(const T &container, int nb)
{
    typename T::const_iterator it;
    it = find(container.begin(), container.end(), nb);
    if (it == container.end())
         throw std::runtime_error("Value not found in container");
    std::cout << "Found" << std::endl;
};

#endif