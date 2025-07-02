#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <vector>

class Span
{
    private:
        int _integers;
        std::vector<int> _container;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span &src);
        Span &operator=(const Span &copy);
        ~Span();

        void addNumber(int nb);
        unsigned int shortestSpan();
        unsigned int longestSpan();
};

#endif