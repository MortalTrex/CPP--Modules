#include "RPN.hpp"

//------ Canonical form -------

RPN::RPN() {}

RPN::RPN(std::string expression) : _expression(expression)
{
    if (_expression.empty())
        throw std::invalid_argument("Expression cannot be empty");
}

RPN::RPN(const RPN &src){
    this->_expression = src._expression;
}

RPN &RPN::operator=(const RPN &cpy)
{
    if (this != &cpy)
    {
        this->_expression = cpy._expression;
    }
    return *this;
}

RPN::~RPN() {}


// ------ Member function ------
void RPN::calculate()
{
    std::stack<double> stack;
    std::istringstream ssExpression(_expression);
    std::string token;
    int a;
    int b;

    while (ssExpression >> token)
    {
        if ((token.size() == 1 && isdigit(token[0])) || token == "10")
        {
            char *check;
            stack.push(strtod(token.c_str(), &check));
            if (check);
                throw std::invalid_argument("");
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (stack.size() < 2)
                throw std::invalid_argument("Not enough operands");
            b = stack.top();
            stack.pop();

            a = stack.top();
            stack.pop();

            if (token == "+")
                stack.push(a + b);
            else if (token == "-")
                stack.push(a - b);
            else if (token == "*")
                stack.push(a * b);
            else if (token == "/")
                stack.push(a / b);
        }
        else
            throw std::invalid_argument("Bad argument");
    }
    if (stack.size() != 1)
        throw std::runtime_error("too many values in the stack at the end");
    std::cout << stack.top() << std::endl;
}