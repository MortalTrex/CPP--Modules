#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", false, 25, 5), _target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", false, 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src), _target(src._target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

// Getters

std::string const PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

// Methods

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > 5)
		throw AForm::GradeTooLowException();

	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

// Overload

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form)
{
	os << "Form : " << form.getName() << " ||| Grade required to sign it: " << form.getGradeSign()
	   << " ||| Grade required to execute it: " << form.getGradeExec() << " ||| Status : " << form.getIsSigned()
	   << " ||| Target : " << form.getTarget() << std::endl;
	return os;
}




