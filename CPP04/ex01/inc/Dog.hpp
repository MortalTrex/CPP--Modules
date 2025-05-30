#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Dog : public Animal
{
    private:
        Brain *_brain;

    public:
        Dog();
        Dog(const Dog &other);
        Dog &operator=(const Dog &other);
        virtual ~Dog();

        // Brain
        std::string getIdea(int i) const;
        void setIdea(int i, const std::string& newIdea);
};

#endif