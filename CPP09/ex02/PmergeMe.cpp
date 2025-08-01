#include "PmergeMe.hpp"

// ------- CANONICAL FORM -------

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &src)
{
    *this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    // if (this != &src) {
    // }
    (void)src;
    return *this;
}

PmergeMe::~PmergeMe(){}

// ------- Methods ---------

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




void PmergeMe::mergeSort(std::deque<unsigned int> &nb)  
{  
    if (nb.size() < 2)
        return;
    std::deque<unsigned int> Main;
    std::deque<unsigned int> Pend;
    size_t  len = nb.size();
    bool Odd = nb.size() % 2 != 0;
    unsigned int tmp = 0;

    if (Odd)
    {
        tmp = nb.back();
        nb.pop_back();
        len--;
    }

    // -----FIRST SORT : FORMER DES PAIRES
    for (size_t i = 0; i < len; i += 2)
    {
        unsigned int a = nb[i];
        unsigned int b = nb[i + 1];
        Main.push_back(std::max(a, b));
        Pend.push_back(std::min(a, b));
    }

    mergeSort(Main); // recursiviter

    if (Odd)
        Pend.push_back(tmp);

    // --------SUITE JACOB
    std::vector<int> insertOrder = generateJacobsthalOrder(Pend.size());


    for (size_t i = 0; i < insertOrder.size(); ++i)
    {
        int val = Pend[insertOrder[i]];

        std::deque<unsigned int>::iterator pos = std::lower_bound(Main.begin(), Main.end(), val);
        Main.insert(pos, val); // cest a cette etape la qu'il y aura une diference de complexiter algorithmique entre deque et vector
    }
    nb = Main;
}

void PmergeMe::mergeSort(std::vector<unsigned int> &nb)  
{  
    if (nb.size() < 2)
        return;
    std::vector<unsigned int> Main;
    std::vector<unsigned int> Pend;
    size_t  len = nb.size();
    bool Odd = nb.size() % 2 != 0;
    unsigned int tmp = 0;

    if (Odd)
    {
        tmp = nb.back();
        nb.pop_back();
        len--;
    }

    // -----FIRST SORT : FORMER DES PAIRES
    for (size_t i = 0; i < len; i += 2)
    {
        unsigned int a = nb[i];
        unsigned int b = nb[i + 1];
        Main.push_back(std::max(a, b));
        Pend.push_back(std::min(a, b));
    }

    mergeSort(Main); // recursiviter

    if (Odd)
        Pend.push_back(tmp);

    // --------SUITE JACOB
    std::vector<int> insertOrder = generateJacobsthalOrder(Pend.size());


    for (size_t i = 0; i < insertOrder.size(); ++i)
    {
        int val = Pend[insertOrder[i]];

        std::vector<unsigned int>::iterator pos = std::lower_bound(Main.begin(), Main.end(), val);
        Main.insert(pos, val); // cest a cette etape la qu'il y aura une diference de complexiter algorithmique entre deque et vector
    }
    nb = Main;
}
