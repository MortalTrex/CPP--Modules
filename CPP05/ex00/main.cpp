#include "Bureaucrat.hpp"

int main()
{
    // Test wrong class instantiation
    std::cout << "\033[34mTesting wrong class instantiation:\033[0m" << std::endl;
    try
    {
        Bureaucrat error = Bureaucrat("error", 153);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "\033[34mTesting too much increment or decrement:\033[0m" << std::endl;

    // Test too much increment or decrement
    try
    {
        Bureaucrat first = Bureaucrat("first", 1);
        Bureaucrat last = Bureaucrat("last", 150);
        
        //Test limit Increment
        std::cout << first << std::endl;
        first.incrementGrade();
        std::cout << first << std::endl;
    
        //Test limit Decrement
        last.decrementGrade();
        std::cout << last << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "\033[34mTesting normal class instantiation:\033[0m" << std::endl;
    // Test normal class instantiation
    try
    {
        Bureaucrat bureaucrat = Bureaucrat("Ralph", 50);
        std::cout << bureaucrat << std::endl;

        // Test increment and decrement
        bureaucrat.incrementGrade();
        std::cout << "After increment: " << bureaucrat << std::endl;
        
        bureaucrat.decrementGrade();
        std::cout << "After decrement: " << bureaucrat << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "\033[34mTest deepcopy:\033[0m" << std::endl;

    Bureaucrat number1("Test", 45);
    Bureaucrat number2(number1);

    number1.incrementGrade();
    std::cout << "Before" << std::endl;
    std::cout << number2 << std::endl << number1 << std::endl;
    std::cout << "After" << std::endl;
    number2 = number1;
    std::cout << number2 << std::endl << number1 << std::endl;
}