#include "./inc/Animal.hpp"
#include "./inc/Cat.hpp"
#include "./inc/Dog.hpp"

int main()
{
    Animal* meta[4];

    Dog*    A = new Dog();
    Cat*    B = new Cat();
    // Animal C; <- this is not possible because Animal is an abstract class
    
    Cat *other = new Cat(*B);
    other->makeSound();
    std::cout << other->getIdea(100) << std::endl;
    delete other;

    for (int i = 0; i < 4; i++)
    {
            if ( i % 2 == 0)
                    meta[i] = new Dog();
            else
                    meta[i] = new Cat();
    }
    B->setIdea(100, "I HAVE IDEA");
    B->setIdea(99, "I HAVE IDEA");

    std::cout << " idea test: " << B->getIdea(100) << std::endl;
    std::cout << " idea test: " << B->getIdea(99) << std::endl;
    std::cout << " idea test: " << B->getIdea(98) << std::endl;

    for (int i = 0; i < 4; i++)
            delete meta[i];
    delete A;
    delete B;
    return 0;
}
