#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", false, 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", false, 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

std::string const RobotomyRequestForm::getTarget() const
{
	return this->_target;
}




