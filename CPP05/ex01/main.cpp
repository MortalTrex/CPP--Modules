#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    // Test form correct 
    std::cout << "\033[34mRight Form Level :\033[0m" << std::endl;
    try
    {
        Bureaucrat first = Bureaucrat("bureaucrat", 34);
        Form form = Form("important", false, 150, 35);
        std::cout << form << std::endl; 
        first.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    // Test form incorrect 
    std::cout << "---------------------" << std::endl;
    std::cout << "\033[34mWrong Form Level\033[0m" << std::endl;

    try
    {
        Bureaucrat first = Bureaucrat("bureaucrat", 34);
        Form form = Form("important", false, 2, 35);
        std::cout << form << std::endl; 
        first.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    //Test bad arguments
    std::cout << "---------------------" << std::endl;
    std::cout << "\033[34mBad arguments for form\033[0m" << std::endl;
    try
    {
        Bureaucrat first = Bureaucrat("bureaucrat", 34);
        Form form = Form("important", false, 0, 35);
        std::cout << form << std::endl; 
        first.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}