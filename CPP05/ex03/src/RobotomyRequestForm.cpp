#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", false, 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", false, 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src), _target(src._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

// Getters

std::string const RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

// Methods

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > 45)
		throw AForm::GradeTooLowException();

	std::cout << "Bzzzzzzzz... " << this->_target << " has been robotomized successfully 50% of the time!" << std::endl;
}

// Overload

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &form)
{
	os << "Form : " << form.getName() << " ||| Grade required to sign it: " << form.getGradeSign()
	   << " ||| Grade required to execute it: " << form.getGradeExec() << " ||| Status : " << form.getIsSigned()
	   << " ||| Target : " << form.getTarget() << std::endl;
	return os;
}





