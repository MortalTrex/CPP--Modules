#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat first = Bureaucrat("first", 1);
    Bureaucrat last = Bureaucrat("last", 150);

    //Test limit Increment
    std::cout << first.getName() << std::endl << first.getGrade() << std::endl;
    first.incrementGrade();
    std::cout << first.getGrade() << std::endl << std::endl;

    //Test limit Decrement
    last.decrementGrade();
    std::cout << last.getName() << std::endl << last.getGrade() << std::endl;
}