#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"


class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
		~PresidentialPardonForm();

		// Getters
		std::string const getTarget() const;

		// Methods
		void execute(const Bureaucrat &executor) const;
};
std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form);

#endif