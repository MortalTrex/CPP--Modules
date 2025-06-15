#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		std::string const _name;
		bool _isSigned;
		size_t const _gradeSign;
		size_t const _gradeExec;

	public:
		AForm();
		AForm(std::string name, bool isSigned, size_t sign, size_t exec);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		// Getters
		std::string const getName() const;
		bool getIsSigned() const;
		size_t getGradeSign() const;
		size_t getGradeExec() const;

		// Methods
		void beSigned(const Bureaucrat &b);
		virtual void execute(const Bureaucrat &executor) const = 0;

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

	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Form not signed";
			}
	};

	class FileOpenException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Failed to open file";
			}
	};

};
std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif