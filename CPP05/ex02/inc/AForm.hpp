#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool _isSigned;
		size_t const _gradeSign;
		size_t const _gradeExec;

	public:
		AForm();
		AForm(std::string name, bool isSigned, size_t sign, size_t exec);
		virtual ~AForm();

		// Getters
		std::string const getName() const;
		bool getIsSigned() const;
		size_t getGradeSign() const;
		size_t getGradeExec() const;

		// Methods
		virtual void beSigned(const Bureaucrat &b) = 0;
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

};
std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif