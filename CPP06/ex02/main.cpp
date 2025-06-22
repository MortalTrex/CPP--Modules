#include "./inc/Base.hpp"
#include "./inc/A.hpp"

Base * generate(void)
{
    Base *res = NULL;
    return (res);
}

void identify(Base* p)
{
    std::cout << p << std::endl;
}

void identify(Base& p)
{
    std::cout << &p << std::endl;
}

int main()
{
    Base *test = generate();
    identify(test);
    identify(*test);
}