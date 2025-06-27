#include "iter.hpp"

void func (int a)
{
    a++;
    std::cout << "a = " << a << std::endl;
}

int main()
{
    int a[3];
    for (int i = 0 ; i < 3 ; i++)
    {
        a[i] = i + 1;
    }
    iter(a, 2, func);
}