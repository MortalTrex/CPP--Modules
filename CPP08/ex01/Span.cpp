#include "Span.hpp"

// CANONICAL FORM

Span::Span(){}

Span::Span(unsigned int N) : _maxSize(N){}

Span::Span(const Span &src) : _maxSize(src._maxSize), _container(src._container){}

Span &Span::operator=(const Span &copy)
{
    if (this != &copy)
    {
        this->_container = copy._container;
        this->_maxSize = copy._maxSize;
    }
    return *this;
}

Span::~Span(){}

// MAIN FUNCTIONS

void Span::addNumber(int nb)
{
    if (_container.size() == _maxSize)
    {
        std::cout << "Limit of numbers reached" << std::endl;
        return;
    }
    _container.push_back(nb);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    for ( ; begin != end; begin++)
    {
        if (_container.size() == _maxSize)
        {
            std::cout << "Limit of numbers reached" << std::endl;
            return;
        }
        _container.push_back(*begin);
    }
}

unsigned int Span::longestSpan()
{
    if (_container.size() < 2)
        throw std::logic_error("Not enough value");
    int min = *std::min_element(_container.begin(), _container.end());
    int max = *std::max_element(_container.begin(), _container.end());
    return max - min;
}

unsigned int Span::shortestSpan()
{
    if (_container.size() < 2)
        throw std::logic_error("Not enough value");
    std::vector<int> sorted = _container;
    std::sort(sorted.begin(), sorted.end());
    int span = longestSpan();
    for (size_t i = 0 ; i < sorted.size() - 1; i++)
    {
        if (sorted[i + 1] - sorted[i] < span)
            span = sorted[i + 1] - sorted[i];
    }
    return span;
}