#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
    int nb[3] = { 4, 3, 5 };
    std::vector<int> vec( nb, nb + 3 );

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);
    lst.push_back(35);


    try {
        easyfind(vec, 4);
        easyfind(lst, 15);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}