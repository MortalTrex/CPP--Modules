#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", false, 25, 5), _target("default")
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", false, 25, 5), _target(target)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

std::string const PresidentialPardonForm::getTarget() const
{
	return this->_target;
}


