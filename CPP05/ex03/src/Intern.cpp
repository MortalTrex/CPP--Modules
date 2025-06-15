#include "../inc/Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(Intern const &src)
{
    *this = src;
}

Intern &Intern::operator=(Intern const &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{

}

// Methods

AForm *Intern::createShrubberyForm(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyForm(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialForm(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string nameForm, std::string target)
{
    std::string tab_level[3] = {"Shrubbery", "Robotomy", "President"};
    AForm* (Intern::*formCreators[3])(const std::string&) = {
        &Intern::createShrubberyForm,
        &Intern::createRobotomyForm,
        &Intern::createPresidentialForm
    };

    for (int i = 0 ; i < 3 ; i++)
    {
        if (tab_level[i] == nameForm)
        {
            std::cout << "Intern creates " << nameForm << " form" << std::endl;
            return (this->*formCreators[i])(target);
        }
    }
    throw FormNotFoundException();
    return NULL;
}


