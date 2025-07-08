#include "RPN.hpp"

// Canonical form

RPN::RPN() {}

RPN::RPN(std::string expression) : expression(expression) {
    if (expression.empty()) {
        throw std::invalid_argument("Expression cannot be empty");
    }
}

RPN::RPN(const RPN &src) {
    this->expression = src.expression;
}

RPN &RPN::operator=(const RPN &cpy) {
    if (this != &cpy) {
        this->expression = cpy.expression;
    }
    return *this;
}

RPN::~RPN() {}


// Calculate the result of the RPN expression

double RPN::calculate() const{
    std::cout << "Calculating RPN expression: " << expression << std::endl;
    return 0.0;
}