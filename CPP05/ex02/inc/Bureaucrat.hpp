#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        std::string const _name;
        size_t _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        // Getters
        std::string const getName() const;
        size_t getGrade() const;
 
        // Methods
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &form);
        void executeForm(const AForm &form) const;

        // Exceptions
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Grade too high!";
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Grade too low!";
                }
        };
};
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif