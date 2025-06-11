#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string const _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();

		// Getters
		std::string const getTarget() const;

		// Methods
		void execute(const Bureaucrat &executor) const;
};

#endif