#include "./inc/Bureaucrat.hpp"
#include "./inc/AForm.hpp"
#include "./inc/PresidentialPardonForm.hpp"
#include "./inc/RobotomyRequestForm.hpp"
#include "./inc/ShrubberyCreationForm.hpp"

int main()
{
    // Test ShrubberyCreationForm
    std::cout << "\033[34mTesting ShrubberyCreationForm:\033[0m" << std::endl;
    try
    {
        Bureaucrat bureaucrat("bureaucrat", 140);

        //AForm *pardonForm = new PresidentialPardonForm("presidential");
	    AForm *shrubberyForm = new ShrubberyCreationForm("shrubbery");
	    //AForm *robotomyForm = new RobotomyRequestForm("robotomy");

        std::cout << shrubberyForm << std::endl;

        bureaucrat.signForm(*shrubberyForm);
        bureaucrat.executeForm(*shrubberyForm);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}