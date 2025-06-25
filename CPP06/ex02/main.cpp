#include "./inc/Base.hpp"
#include "./inc/A.hpp"
#include "./inc/B.hpp"
#include "./inc/C.hpp"

Base * generate(void)
{
    srand(time(0));
    int rdmValue;

    rdmValue = rand() % 3;
    if (rdmValue == 0)
        return new A;
    else if (rdmValue == 1)
        return new B;
    else if (rdmValue == 2)
        return new C;
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
    return ;
}

void identify(Base& p)
{
    if (dynamic_cast<A*>(&p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(&p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(&p))
        std::cout << "C" << std::endl;
    return ;
}

int main()
{
    Base *test = generate();
    std::cout << "Pointer version:" << std::endl;
    identify(test);
    std::cout << "Reference version:" << std::endl;
    identify(*test);

    delete test;    
    return 0;
}