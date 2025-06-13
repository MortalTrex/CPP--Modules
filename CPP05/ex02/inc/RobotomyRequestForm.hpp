#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string const _target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();

		// Getters
		std::string const getTarget() const;

		// Methods
		virtual void beSigned(const Bureaucrat &b);
		void execute(const Bureaucrat &executor) const;
};

#endif