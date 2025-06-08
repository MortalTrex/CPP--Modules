#include "../inc/Cat.hpp"

Cat::Cat() 
{
    _type = "Cat";
    _brain = new Brain();
    std::cout << "\033[32mCat default constructor called\033[0m" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    this->_brain = new Brain(*other._brain);
    this->_type = other._type;
    std::cout << "\033[32mCat copy constructor called\033[0m" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "\033[32mCat assignment operator called\033[0m" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
        *this->_brain = *other._brain;
    }
    return *this;
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "\033[31mCat destructor called\033[0m" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow !" << std::endl;
}

void Cat::setIdea(int i, const std::string& newIdea) 
{
    if (i < 0 || i > 99)
    {
        std::cout << "Index is outside the range" << std::endl;
        return ;
    }
    this->_brain->setIdea(i, newIdea);
}

std::string Cat::getIdea(int i) const
{
    if (i < 0 || i > 99)
        return "Index is outside the range";
    if (this->_brain->getIdea(i).empty())
        return "No idea";
    return this->_brain->getIdea(i);
}