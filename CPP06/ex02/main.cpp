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
    else if (rdmValue == 2)
        return new B();
    else if (rdmValue == 3)
        return new C();
    return new Base();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Base" << std::endl;
    return ;
}

void identify(Base& p)
{
    (void) p;
}

int main()
{
    Base *test = generate();
    identify(test);
    identify(*test);

    delete test;    
    return 0;
}