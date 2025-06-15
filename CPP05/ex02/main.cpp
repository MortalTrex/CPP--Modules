#include "./inc/Bureaucrat.hpp"
#include "./inc/AForm.hpp"
#include "./inc/PresidentialPardonForm.hpp"
#include "./inc/RobotomyRequestForm.hpp"
#include "./inc/ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat lowlevel("lowlevel", 140);
    Bureaucrat highlevel("highlevel", 1);

    AForm *shrubberyForm = new ShrubberyCreationForm("President");
    AForm *robotomyForm = new RobotomyRequestForm("robotomy");
    AForm *presidentialForm = new PresidentialPardonForm("presidential");

    // Test ShrubberyCreationForm
    std::cout << "\033[31mTesting Wrong ShrubberyCreationForm:\033[0m" << std::endl;
    try
    {
        lowlevel.signForm(*shrubberyForm);
        lowlevel.executeForm(*shrubberyForm);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    // Test Good ShrubberyCreationForm
    std::cout << "\033[34mTesting Good ShrubberyCreationForm:\033[0m" << std::endl;
    try
    {
        std::cout << *shrubberyForm << std::endl;
        highlevel.signForm(*shrubberyForm);
        std::cout << *shrubberyForm << std::endl;
        highlevel.executeForm(*shrubberyForm);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    // Test RobotomyRequestForm
    std::cout << "\033[34mTesting RobotomyRequestForm:\033[0m" << std::endl;
    try
    {
        highlevel.signForm(*robotomyForm);
        highlevel.executeForm(*robotomyForm);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    // Test PresidentialPardonForm
    std::cout << "\033[34mTesting PresidentialPardonForm:\033[0m" << std::endl;
    try
    {
        highlevel.signForm(*presidentialForm);
        highlevel.executeForm(*presidentialForm);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    delete shrubberyForm;
    delete robotomyForm;
    delete presidentialForm;
}