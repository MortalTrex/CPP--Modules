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
    if (_count == _integers)
    {
        std::cout << "Limit of numbers reached" << std::endl;
        return;
    }
    _container.push_back(nb);
    _count++;
}

unsigned int Span::longestSpan()
{
    int min = *std::min_element(_container.begin(), _container.end());
    int max = *std::max_element(_container.begin(), _container.end());
    return max - min;
}

unsigned int Span::shortestSpan()
{
    std::vector<int> sorted = _container;
    std::sort(sorted.begin(), sorted.end());
    unsigned int span = longestSpan();
    for (size_t i = 0 ; i < sorted.size() ; i++)
    {
        std::cout << span << std::endl;
        if (sorted[i + 1] - sorted[i] < static_cast<int>(span))
            span = sorted[i + 1] - sorted[i];
    }
    return span;
}