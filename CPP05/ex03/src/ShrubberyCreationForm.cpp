#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", false, 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", false, 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src), _target(src._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// Getters

std::string const ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

// Methods

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string fileName = this->_target + "_shrubbery";
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > 137)
		throw AForm::GradeTooLowException();

	std::ofstream ofs(fileName.c_str());
	if (!ofs.is_open())
		throw AForm::FileOpenException();


	ofs << "               ,@@@@@@@,\n";
	ofs << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
	ofs << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
	ofs << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
	ofs << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
	ofs << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
	ofs << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
	ofs << "       |o|        | |         | |\n";
	ofs << "       |.|        | |         | |\n";
	ofs << " \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";


	ofs.close();
}

// Overload

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &form)
{
	os << "Form : " << form.getName() << " ||| Grade required to sign it: " << form.getGradeSign()
	   << " ||| Grade required to execute it: " << form.getGradeExec() << " ||| Status : " << form.getIsSigned()
	   << " ||| Target : " << form.getTarget() << std::endl;
	return os;
}

