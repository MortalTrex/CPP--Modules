#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <string>

class PmergeMe
{
    private:
        std::vector <int> _numbers;

    public:
        PmergeMe();
        PmergeMe(std::vector<int> values);
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
        ~PmergeMe();

        void executeMerge();
};

#endif