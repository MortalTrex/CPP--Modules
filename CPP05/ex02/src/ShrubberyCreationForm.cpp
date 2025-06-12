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

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > 137)
		throw AForm::GradeTooLowException();

	std::ofstream ofs(this->_target + "_shrubbery");
	if (!ofs.is_open())
		throw AForm::FileOpenException();

	std::ofstream ofs(this->_target + "_shrubbery");
	if (!ofs)
		throw std::runtime_error("Failed to open output file");

	ofs << "               ,@@@@@@@,\n";
	ofs << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
	ofs << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
	ofs << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
	ofs << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
	ofs << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
	ofs << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
	ofs << "       |o|        | |         | |\n";
	ofs << "       |.|        | |         | |\n";
	ofs << "jgs \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";


	ofs.close();
}

