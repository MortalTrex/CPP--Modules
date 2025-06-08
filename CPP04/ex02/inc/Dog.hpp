#ifndef DOG_H
#define DOG_H

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Dog : public AAnimal
{
    private:
        Brain *_brain;

    public:
        Dog();
        Dog(const Dog &other);
        Dog &operator=(const Dog &other);
        ~Dog();

        void makeSound() const;

        // Brain
        std::string getIdea(int i) const;
        void setIdea(int i, const std::string& newIdea);
};

#endif