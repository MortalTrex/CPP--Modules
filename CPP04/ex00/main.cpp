#include "./inc/Animal.hpp"
#include "./inc/Cat.hpp"
#include "./inc/Dog.hpp"
#include "./inc/WrongAnimal.hpp"
#include "./inc/WrongCat.hpp"
#include "./inc/WrongDog.hpp"

int main()
{
    //MAIN TEST
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* j2 = new Dog();
    const Animal* i = new Cat();

    
    j = j2;
    std::cout << "------------------" << std::endl;
    std::cout << "\033[31mDog Type:\033[0m " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << "\033[31mCat Type:\033[0m " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << "\033[31mCat sound:\033[0m " << std::endl;
    i->makeSound();
    std::cout << "\033[31mDog sound:\033[0m " << std::endl;
    j->makeSound();
    std::cout << "\033[31mAnimal sound:\033[0m " << std::endl;
    meta->makeSound();
    std::cout << "-------------------" << std::endl;
    delete(meta);
    delete(j);
    delete(i);

    std::cout << std::endl;

    //TEST WRONG ANIMAL
    std::cout << "------------------" << std::endl;
    std::cout << "WRONG ANIMAL TEST" << std::endl;
    std::cout << "------------------" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongDog = new WrongDog();
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << "-------------------" << std::endl;
    std::cout << "\033[31mWrongDog Type:\033[0m " << std::endl;
    std::cout << wrongDog->getType() << " " << std::endl;
    std::cout << "\033[31mWrongCat Type:\033[0m " << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;
    std::cout << "\033[31mWrongCat sound:\033[0m " << std::endl;
    wrongCat->makeSound();
    std::cout << "\033[31mWrongDog sound:\033[0m " << std::endl;
    wrongDog->makeSound();
    std::cout << "\033[31mWrongAnimal sound:\033[0m " << std::endl;
    wrongMeta->makeSound();
    std::cout << "-------------------" << std::endl;
    delete(wrongMeta);
    delete(wrongDog);
    delete(wrongCat);
}