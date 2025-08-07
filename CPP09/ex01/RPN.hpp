#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <list>
#include <string>
#include <stdexcept>
#include <sstream>
#include <cstdlib>

class RPN
{
    private:
        std::string         _expression;
    public:
        RPN();
        RPN(std::string expression);
        RPN(const RPN &src);
        RPN &operator=(const RPN &cpy);
        ~RPN();

        void calculate();
};

#endif