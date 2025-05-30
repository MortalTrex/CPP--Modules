#include "./inc/Animal.hpp"
#include "./inc/Cat.hpp"
#include "./inc/Dog.hpp"

#define ARRAY_SIZE 4

int main(void)
{
    // MAIN TEST
	Animal *meta[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (i % 2)
            meta[i] = new Dog();
        else
            meta[i] = new Cat();
    }

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << "Animal type: " << meta[i]->getType() << std::endl;
		meta[i]->makeSound();
	}

    for (int i = 0; i < ARRAY_SIZE; i++)
        delete meta[i];
    
    std::cout << "--------------------------------" << std::endl;

    //TEST DEEP COPY
    std::cout << std::endl << "TEST DEEP COPY" << std::endl << std::endl;
    Cat*	cat1 = new Cat();
    Cat* 	cat2 = new Cat();
    
    *cat1 = *cat2;
    cat1->setIdea(99, "I think I will control humans");
    cat2->setIdea(99, "I need food");
    cat2->setIdea(130, "I need food");
    std::cout << cat1->getIdea(99) << std::endl;
    std::cout << cat2->getIdea(99) << std::endl;
    
    delete cat2;
    
    std::cout << "--------------------------------" << std::endl;

    // TEST ASSIGNMENT
    std::cout << std::endl << "TEST ASSIGNMENT" << std::endl << std::endl;
    Cat *cat3 = new Cat(*cat1);

    cat3->makeSound();
    cat1->setIdea(99, "I think I will control humans");
    std::cout << cat3->getIdea(100) << std::endl;
    std::cout << cat3->getIdea(65) << std::endl;

    delete cat1;
    delete cat3;
}