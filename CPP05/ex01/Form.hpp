#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		bool _isSigned;
		size_t const _gradeSign;
		size_t const _gradeExec;

	public:
		Form();
		Form(std::string name, bool isSigned, size_t sign, size_t exec);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		// Getters
		std::string const getName() const;
		bool getIsSigned() const;
		size_t getGradeSign() const;
		size_t getGradeExec() const;

		// Methods
		void beSigned(const Bureaucrat &b);
	
	// Exceptions
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Grade too high";
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Grade too low";
			}
	};
};
std::ostream &operator<<(std::ostream &os, const Form &form);

#endif