#include "Form.hpp"

// Main methods of the Form class

Form::Form() : _name("Default"), _isSigned(false), _gradeSign(50), _gradeExec(50)
{

}

Form::Form(std::string name, bool isSigned, size_t sign, size_t exec) : 
_name(name), _isSigned(isSigned), _gradeSign(sign), _gradeExec(exec)
{
	if (sign <= 0 || exec <= 0)
		throw Form::GradeTooHighException();
	else if (sign > 150 || exec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), 
_gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{

}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

Form::~Form()
{

}

// Overload

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form : " << form.getName() << " ||| Grade required to sign it: " << form.getGradeSign() 
	<< " ||| Grade required to execute it: " << form.getGradeExec() << " ||| Status : " << form.getIsSigned() << std::endl;
	return os;
}

// Getters

std::string const Form::getName() const
{
	return this->_name;
}

bool Form::getIsSigned() const
{
	return this->_isSigned;
}


size_t Form::getGradeSign() const
{
	return this->_gradeSign;
}

size_t Form::getGradeExec() const
{
	return this->_gradeExec;
}

// Methods

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->getGradeSign() || b.getGrade() > this->getGradeExec())
		throw Form::GradeTooLowException();
	_isSigned = true;
}