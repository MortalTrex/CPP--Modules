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
    std::list<double> list;
    std::istringstream ssExpression(_expression);
    std::string token;

    while (ssExpression >> token)
    {
        char *check;
        double value = std::strtod(token.c_str(), &check);
        if (*check == '\0') // conversion complète réussie
        {
            list.push_back(value);
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (list.size() < 2)
                throw std::invalid_argument("Not enough operands");

            double b = list.back(); 
            list.pop_back();
            double a = list.back();
            list.pop_back();

            if (token == "+")
                list.push_back(a + b);
            else if (token == "-")
                list.push_back(a - b);
            else if (token == "*")
                list.push_back(a * b);
            else if (token == "/")
            {
                if (b == 0)
                    throw std::invalid_argument("Division by zero");
                list.push_back(a / b);
            }
        }
        else
            throw std::invalid_argument("Bad argument: " + token);
    }

    if (list.size() != 1)
        throw std::runtime_error("Too many values in the list at the end");

    std::cout << list.back() << std::endl;
}
