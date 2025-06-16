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
    typedef AForm* (Intern::*FormCreator)(const std::string&);

    std::pair<std::string, FormCreator> tab[] = {
        std::make_pair(std::string("shrubbery creation"), &Intern::createShrubberyForm),
        std::make_pair(std::string("robotomy request"), &Intern::createRobotomyForm),
        std::make_pair(std::string("presidential pardon"), &Intern::createPresidentialForm)
    };


    for (int i = 0 ; i < 3 ; i++)
    {
        if (tab[i].first == nameForm)
        {
            std::cout << "Intern creates " << nameForm << " form" << std::endl;
            return (this->*tab[i].second)(target);
        }
    }
    throw FormNotFoundException();
}



