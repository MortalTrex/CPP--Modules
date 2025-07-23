#include "PmergeMe.hpp"

// ------- CANONICAL FORM -------

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(std::vector<int> values) : _numbers(values){}

PmergeMe::PmergeMe(const PmergeMe &src) : _numbers(src._numbers){}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
        this->_numbers = src._numbers;
    return *this;
}

PmergeMe::~PmergeMe(){}

// ------- Methods ---------

void PmergeMe::executeMerge()
{
    for (size_t i = 0 ; i < _numbers.size() ; i++)
    {
        std::cout << _numbers[i] << std::endl;
    }
}