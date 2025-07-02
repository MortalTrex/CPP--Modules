#include "Span.hpp"

// CANONICAL FORM

Span::Span(){}

Span::Span(unsigned int N) : _integers(N){}

Span::Span(const Span &src) : _integers(src._integers){}

Span &Span::operator=(const Span &copy)
{
    if (this != &copy)
    {
        this->_integers = copy._integers;
    }
    return *this;
}

Span::~Span(){}

// MAIN FUNCTIONS

void Span::addNumber(int nb)
{
    _container.push_back(nb);
}

unsigned int Span::longestSpan()
{
    return 45;
}

unsigned int Span::shortestSpan()
{
    return 42;
}