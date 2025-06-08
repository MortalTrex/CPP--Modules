#ifndef CAT_H
#define CAT_H

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Cat : public AAnimal
{
    private:
        Brain *_brain;

    public:
        Cat();
        Cat(const Cat &other);
        Cat &operator=(const Cat &other);
        ~Cat();

        void makeSound() const;

        // Brain
        std::string getIdea(int i) const;
        void setIdea(int i, const std::string& newIdea);
};

#endif