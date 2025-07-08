#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>

class RPN {
    private:
        std::string expression;
    public:
        RPN();
        RPN(std::string expression);
        RPN(const RPN &src);
        RPN &operator=(const RPN &cpy);
        ~RPN();

        double calculate() const;
};

#endif