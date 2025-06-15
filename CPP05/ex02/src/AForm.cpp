#include "../inc/AForm.hpp"

// Main methods of the Form class

AForm::AForm() : _name("Default"), _isSigned(false), _gradeSign(50), _gradeExec(50)
{

}

AForm::AForm(std::string name, bool isSigned, size_t sign, size_t exec) : 
_name(name), _isSigned(isSigned), _gradeSign(sign), _gradeExec(exec)
{
	if (sign <= 0 || exec <= 0)
		throw AForm::GradeTooHighException();
	else if (sign >= 150 || exec >= 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), 
_gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{

}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm()
{

}

// Overload

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Form : " << form.getName() << " ||| Grade required to sign it: " << form.getGradeSign() 
	<< " ||| Grade required to execute it: " << form.getGradeExec() << " ||| Status : " << form.getIsSigned() << std::endl;
	return os;
}

// Getters

std::string const AForm::getName() const
{
	return this->_name;
}

bool AForm::getIsSigned() const
{
	return this->_isSigned;
}


size_t AForm::getGradeSign() const
{
	return this->_gradeSign;
}

size_t AForm::getGradeExec() const
{
	return this->_gradeExec;
}

// Methods

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->getGradeSign() || b.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	_isSigned = true;
}