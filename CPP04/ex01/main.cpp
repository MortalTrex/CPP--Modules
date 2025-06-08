#include "./inc/Animal.hpp"
#include "./inc/Cat.hpp"
#include "./inc/Dog.hpp"
#include "./inc/WrongAnimal.hpp"
#include "./inc/WrongCat.hpp"
#include "./inc/WrongDog.hpp"

#define ARRAY_SIZE 4

int main(void)
{
    // MAIN TEST
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;//should not create a leak
    delete i;

    std::cout << "--------------------------------" << std::endl;

    // TEST ANIMAL ARRAY
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

    Dog basic;
    {
        Dog tmp = basic;
        std::cout << "basic brain idea 0: " << basic.getIdea(0) << std::endl;
        std::cout << "tmp brain idea 0: " << tmp.getIdea(0) << std::endl;
        basic.setIdea(0, "I want to play");
        std::cout << "basic brain idea 0 after change: " << basic.getIdea(0) << std::endl;
        std::cout << "tmp brain idea 0 after basic change: " << tmp.getIdea(0) << std::endl;
    }

    std::cout << "--------------------------------" << std::endl;

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
    cat1->setIdea(65, "I want to sleep");
    Cat *cat3 = new Cat(*cat1);

    cat3->makeSound();
    std::cout << cat3->getIdea(99) << std::endl;
    std::cout << cat3->getIdea(65) << std::endl;
    cat3->setIdea(65, "I want to play");
    std::cout << cat3->getIdea(65) << std::endl;
    std::cout << cat1->getIdea(65) << std::endl;

    delete cat1;
    delete cat3;

    std::cout << "--------------------------------" << std::endl;

   //TEST WRONG ANIMAL
    // std::cout << "------------------" << std::endl;
    // std::cout << "WRONG ANIMAL TEST" << std::endl;
    // std::cout << "------------------" << std::endl;
    // const WrongAnimal* wrongMeta = new WrongAnimal();
    // const WrongAnimal* wrongDog = new WrongDog();
    // const WrongAnimal* wrongCat = new WrongCat();
    // std::cout << "-------------------" << std::endl;
    // std::cout << "\033[31mWrongDog Type:\033[0m " << std::endl;
    // std::cout << wrongDog->getType() << " " << std::endl;
    // std::cout << "\033[31mWrongCat Type:\033[0m " << std::endl;
    // std::cout << wrongCat->getType() << " " << std::endl;
    // std::cout << "\033[31mWrongCat sound:\033[0m " << std::endl;
    // wrongCat->makeSound();
    // std::cout << "\033[31mWrongDog sound:\033[0m " << std::endl;
    // wrongDog->makeSound();
    // std::cout << "\033[31mWrongAnimal sound:\033[0m " << std::endl;
    // wrongMeta->makeSound();
    // delete(wrongMeta);
    // delete(wrongDog);
    // delete(wrongCat);

    std::cout << "--------------------------------" << std::endl;
    std::cout <<"DELETED FROM DEEP COPY" << std::endl;

}