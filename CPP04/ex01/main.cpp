#include "./inc/Animal.hpp"
#include "./inc/Cat.hpp"
#include "./inc/Dog.hpp"

int main(void)
{
	Animal* meta[4];

    Dog*	A = new Dog();

    Cat*	B = new Cat();
    Cat* 	C = new Cat();
    Cat*	D = new Cat();


    //TEST DEEP COPY

    *C = *D;
    C->setIdea(99, "I HAVE IDEA");
    D->setIdea(99, "I HAVE IDEA FOR DEEP COPY");

    std::cout << C->getIdea(99) << std::endl;
    std::cout << D->getIdea(99) << std::endl;

    delete C;
    delete D;
    
    Cat *other = new Cat(*B);
    other->makeSound();
    //std::cout << other->getIdea(100) << std::endl;
    delete other;
    
    for (int i = 0; i < 4; i++)
    {
        if ( i % 2 == 0)
            meta[i] = new Dog();
        else
            meta[i] = new Cat();
    }
    //B->setIdea(100, "I HAVE IDEA");
    B->setIdea(99, "I HAVE IDEA");

    //std::cout << " idea test: " << B->getIdea(100) << std::endl;
    std::cout << " idea test: " << B->getIdea(99) << std::endl;
    std::cout << " idea test: " << B->getIdea(98) << std::endl;

    for (int i = 0; i < 4; i++)
        delete meta[i];
    delete A;
    delete B;
}