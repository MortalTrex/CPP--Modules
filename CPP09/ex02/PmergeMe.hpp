#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <cstdlib>
#include <string>
#include <utility>
#include <ctime>
#include <algorithm>


class PmergeMe
{
    private:
        std::vector<std::pair <int, int> > _pairs;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
        ~PmergeMe();

        void mergeSort(std::vector<unsigned int> &nb, size_t &count);
        void mergeSort(std::deque<unsigned int> &nb);
};

#endif