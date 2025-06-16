#include "./inc/Bureaucrat.hpp"
#include "./inc/Intern.hpp"

int main()
{
    // SUBJECT TEST
    try
    {
        std::cout << "\033[34mTesting Subject Example:\033[0m" << std::endl;
        Intern  someRandomIntern;
        AForm*  rrf;
    
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        delete rrf;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    // MORE TESTS
    try 
    {
        Bureaucrat highlevel("highlevel", 1);
    
        Intern intern = Intern();
        std::cout << "\033[34mTesting Intern:\033[0m" << std::endl;
        AForm *shrubberyForm = intern.makeForm("shrubbery creation", "Garden");
        AForm *robotomyForm = intern.makeForm("robotomy request", "Robot");
        AForm *presidentialForm = intern.makeForm("presidential pardon", "President");

        std::cout << "\033[34mTesting ShrubberyCreationForm:\033[0m" << std::endl;
        std::cout << *shrubberyForm << std::endl;
        highlevel.signForm(*shrubberyForm);
        highlevel.executeForm(*shrubberyForm);
        std::cout << *shrubberyForm << std::endl;

        std::cout << "\033[34mTesting RobotomyRequestForm:\033[0m" << std::endl;
        std::cout << *robotomyForm << std::endl;
        highlevel.signForm(*robotomyForm);
        highlevel.executeForm(*robotomyForm);
        std::cout << *robotomyForm << std::endl;

        std::cout << "\033[34mTesting PresidentialPardonForm:\033[0m" << std::endl;
        std::cout << *presidentialForm << std::endl;
        highlevel.signForm(*presidentialForm);
        highlevel.executeForm(*presidentialForm);
        std::cout << *presidentialForm << std::endl;

        delete shrubberyForm;
        delete robotomyForm;
        delete presidentialForm;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    } 
}