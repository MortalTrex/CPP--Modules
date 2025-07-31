#include "PmergeMe.hpp"

// ------- CANONICAL FORM -------

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &src)
{
    *this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src) {
        _pairs = src._pairs;
        _mainChain = src._mainChain;
        _pend = src._pend;
    }
    return *this;
}

PmergeMe::~PmergeMe(){}

// ------- Methods ---------

void sortPairsBySecond(std::vector< std::pair<int, int> >& pairs)
{
    for (size_t i = 1; i < pairs.size(); ++i)
    {
        std::pair<int, int> key = pairs[i];
        int j = i - 1;

        // Décaler les paires dont .second est plus grand
        while (j >= 0 && pairs[j].second > key.second)
        {
            pairs[j + 1] = pairs[j];
            --j;
        }

        pairs[j + 1] = key;
    }
}

std::vector<int> generateJacobsthalOrder(int size)
{
    std::vector<int> order;
    std::vector<bool> used(size, false);

    int j0 = 0;
    int j1 = 1;

    if (j1 < size)
    {
        order.push_back(j1);
        used[j1] = true;
    }

    while (true)
    {
        int next = j1 + 2 * j0;
        if (next >= size)
            break;
        if (!used[next])
        {
            order.push_back(next);
            used[next] = true;
        }
        j0 = j1;
        j1 = next;
    }

    // Ajouter les indices manquants dans l'ordre croissant
    for (int i = 0; i < size; ++i)
        if (!used[i])
            order.push_back(i);
    return order;
}


// void PmergeMe::mergeSort(std::vector<int> &nb)  
// {  
//     if (nb.size() == 1)
//         return;
//     std::vector< std::_pairs<int, int> > _pairs;
//     std::vector<int> _mainChain;
//     std::vector<int> pend;
//     int lastNb = -1;

//     // -----FIRST SORT : FORMER DES PAIRES
//     for (size_t i = 0; i + 1 < nb.size(); i += 2)
//     {
//         if (nb[i] <= nb[i + 1])
//             _pairs.push_back(std::make_pair(nb[i], nb[i + 1]));
//         if (nb[i] > nb[i + 1])
//             _pairs.push_back(std::make_pair(nb[i + 1], nb[i]));
//     }
//     if (nb.size() % 2 != 0)
//         lastNb = nb[nb.size() - 1];

//     sortPairsBySecond(_pairs);
//     // print _pairs
//     std::cout << "PAIRS : ";
//     for (size_t i = 0 ; i < _pairs.size() ; i++)
//         std::cout << "(" << _pairs[i].first << ", " << _pairs[i].second << ") ";
//     std::cout << std::endl;

//     // -----SECOND SORT : _mainChain AND PEND
//     for (size_t i = 0 ; i < _pairs.size() ; i++)
//     {
//         _mainChain.push_back(_pairs[i].second);
//         pend.push_back(_pairs[i].first);
//     }
//     if (lastNb != -1)
//         pend.push_back(lastNb);

//     // print main and pend
//     std::cout << "Main chain : ";
//     for (size_t i = 0 ; i < _mainChain.size() ; i++)
//         std::cout << _mainChain[i] << " ";
//     std::cout << std::endl;

//     std::cout << "Pend : ";
//     for (size_t i = 0 ; i < pend.size() ; i++)
//         std::cout << pend[i] << " ";
//     std::cout << std::endl;

//     // --------SUITE JACOB
//     std::vector<int> insertOrder = generateJacobsthalOrder(pend.size());
//     std::cout << "Order Jacobsthal : ";
//     for (size_t i = 0; i < insertOrder.size() ; i++)
//         std::cout << insertOrder[i] << " ";
//     std::cout << std::endl;


//     for (size_t i = 0; i < insertOrder.size(); i++)
//     {
//         int val = pend[insertOrder[i]];

//         std::vector<int>::iterator pos = std::lower_bound(_mainChain.begin(), _mainChain.end(), val);
//         _mainChain.insert(pos, val);
//     }
//     nb = _mainChain;
// }

void PmergeMe::mergeSort(std::vector<int> &nb)  
{  
    if (nb.size() == 1)
        return;
    int lastNb = -1;

    // -----FIRST SORT : FORMER DES PAIRES
    for (size_t i = 0; i + 1 < nb.size(); i += 2)
    {
        if (nb[i] <= nb[i + 1])
            _pairs.push_back(std::make_pair(nb[i], nb[i + 1]));
        else if (nb[i] > nb[i + 1])
            _pairs.push_back(std::make_pair(nb[i + 1], nb[i]));
    }
    if (nb.size() % 2 != 0)
        lastNb = nb[nb.size() - 1];

    // print _pairs
    std::cout << "PAIRS : ";
    for (size_t i = 0 ; i < _pairs.size() ; i++)
        std::cout << "(" << _pairs[i].first << ", " << _pairs[i].second << ") ";
    std::cout << std::endl;

    // -----SECOND SORT : _mainChain AND PEND
    // for (size_t i = 0 ; i < _pairs.size() ; i++)
    // {
    //     _mainChain.push_back(_pairs[i].second);
    //     pend.push_back(_pairs[i].first);
    // }
    // if (lastNb != -1)
    //     pend.push_back(lastNb);

    // // print main and pend
    // std::cout << "Main chain : ";
    // for (size_t i = 0 ; i < _mainChain.size() ; i++)
    //     std::cout << _mainChain[i] << " ";
    // std::cout << std::endl;

    // std::cout << "Pend : ";
    // for (size_t i = 0 ; i < pend.size() ; i++)
    //     std::cout << pend[i] << " ";
    // std::cout << std::endl;

    // // --------SUITE JACOB
    // std::vector<int> insertOrder = generateJacobsthalOrder(pend.size());
    // std::cout << "Order Jacobsthal : ";
    // for (size_t i = 0; i < insertOrder.size() ; i++)
    //     std::cout << insertOrder[i] << " ";
    // std::cout << std::endl;


    // for (size_t i = 0; i < insertOrder.size(); i++)
    // {
    //     int val = pend[insertOrder[i]];

    //     std::vector<int>::iterator pos = std::lower_bound(_mainChain.begin(), _mainChain.end(), val);
    //     _mainChain.insert(pos, val);
    // }
    nb = _mainChain;
}