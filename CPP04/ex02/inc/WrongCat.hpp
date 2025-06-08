#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class WrongCat : public WrongAnimal
{
    private:
        Brain *_brain;
    public:
        WrongCat();
        WrongCat(const WrongCat &other);
        WrongCat &operator=(const WrongCat &other);
        ~WrongCat();

        void makeSound() const;

        std::string getIdea(int i) const;
        void setIdea(int i, const std::string& newIdea);
};

#endif