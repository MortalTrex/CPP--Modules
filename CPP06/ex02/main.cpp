#include "./inc/Base.hpp"
#include "./inc/A.hpp"
#include "./inc/B.hpp"
#include "./inc/C.hpp"

Base * generate(void)
{
    int rdmValue;

    rdmValue = rand() % 3 + 1;
    if (rdmValue == 1)
        return new A();
    if (rdmValue == 2)
        return new B();
    if (rdmValue == 3)
        return new C();
}

void identify(Base* p)
{
    std::cout << p << std::endl;
    return ;
}

void identify(Base& p)
{
    std::cout << &p << std::endl;
    return ;
}

int main()
{
    Base *test = generate();
    identify(test);
    identify(*test);

    return 0;
}