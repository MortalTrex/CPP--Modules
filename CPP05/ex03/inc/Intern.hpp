#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class ShrubberyCreationForm;

class Intern
{
    private:
        AForm* createShrubberyForm(const std::string &target);
        AForm* createRobotomyForm(const std::string &target);
        AForm* createPresidentialForm(const std::string &target);
    
    public:
        Intern();
        Intern(Intern const &src);
        Intern &operator=(Intern const &other);
        ~Intern();

        // Exceptions
        class FormNotFoundException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Form not found";
                }
        };

        //Methods
        AForm* makeForm(std::string nameForm, std::string target);
};

#endif