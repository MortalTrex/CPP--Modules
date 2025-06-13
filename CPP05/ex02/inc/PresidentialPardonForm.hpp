#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"


class PresidentialPardonForm : public AForm
{
	private:
		std::string const _target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();

		// Getters
		std::string const getTarget() const;

		// Methods
		void beSigned(const Bureaucrat &b);
		void execute(const Bureaucrat &executor) const;
};

#endif