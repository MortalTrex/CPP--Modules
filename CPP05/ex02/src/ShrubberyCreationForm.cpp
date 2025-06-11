#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", false, 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", false, 145, 137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string const ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	try
	{
		/* code */
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}