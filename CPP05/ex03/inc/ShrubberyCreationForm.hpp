#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>

#include "AForm.hpp"


class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
		~ShrubberyCreationForm();

		// Getters
		std::string const getTarget() const;

		// Methods
		void execute(const Bureaucrat &executor) const;
};
std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &form);

#endif