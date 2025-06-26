#include "whatever.hpp"

int main()
{
    std::cout << max(6.0, 3.0) << std::endl;
    std::cout << max(3, 3) << std::endl;

    std::cout << min(6.0, 3.0) << std::endl;

    int a = 4;
    int b = 5;
    swap(a, b);
    std::cout << "a = " << a << " b = " << b << std::endl;
}