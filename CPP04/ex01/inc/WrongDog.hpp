#ifndef WRONGDOG_H
#define WRONGDOG_H

#include "WrongAnimal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class WrongDog : public WrongAnimal
{
    private:
        Brain *_brain;
    public:
        WrongDog();
        WrongDog(const WrongDog &other);
        WrongDog &operator=(const WrongDog &other);
        ~WrongDog();

        void makeSound() const;

        std::string getIdea(int i) const;
        void setIdea(int i, const std::string& newIdea);
};

#endif