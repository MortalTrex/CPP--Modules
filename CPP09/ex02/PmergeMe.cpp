#include "PmergeMe.hpp"

// ------- CANONICAL FORM -------

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &src)
{
    *this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
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
    int next = j1 + 2 * j0;

    if (size == 1)
    {
        order.push_back(0);
        return order;
    }
    order.push_back(1);
    used[1] = true;

    while (next < size)
    {
        if (!used[next])
        {   
            order.push_back(next);
            used[next] = true;
        }
        j0 = j1;
        j1 = next;
        next = j1 + 2 * j0;
    }
    for (int i = 0; i < size; ++i)
        if (!used[i])
            order.push_back(i);
    return order;
}

// DEQUE VERSION
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

    for (size_t i = 0; i < len; i += 2)
    {
        unsigned int a = nb[i];
        unsigned int b = nb[i + 1];
        Main.push_back(std::max(a, b));
        Pend.push_back(std::min(a, b));
    }

    mergeSort(Main);

    if (Odd)
        Pend.push_back(tmp);

    std::vector<int> insertOrder = generateJacobsthalOrder(Pend.size());
    for (size_t i = 0; i < insertOrder.size(); i++)
    {
        int val = Pend[insertOrder[i]];
        std::deque<unsigned int>::iterator pos = std::lower_bound(Main.begin(), Main.end(), val);
        Main.insert(pos, val);
    }
    nb = Main;
}

#include <cmath>

// VECTOR VERSION
void PmergeMe::mergeSort(std::vector<unsigned int> &listNb, size_t &count)  
{  
    if (listNb.size() < 2)
        return;

    std::vector<unsigned int> Main;
    std::vector<unsigned int> Pend;
    size_t  len = listNb.size();
    bool Odd = listNb.size() % 2 != 0;
    unsigned int tmp = 0;

    if (Odd)
    {
        tmp = listNb.back();
        listNb.pop_back();
        len--;
    }

    for (size_t i = 0; i < len; i += 2)
    {
        unsigned int a = listNb[i];
        unsigned int b = listNb[i + 1];
        count++;
        Main.push_back(std::max(a, b));
        Pend.push_back(std::min(a, b));
    }

    mergeSort(Main, count);

    if (Odd)
        Pend.push_back(tmp);

    std::vector<int> jacobList = generateJacobsthalOrder(Pend.size());

    std::cout << "Main: ";
    for (size_t i = 0; i < Main.size(); i++)
        std::cout << Main[i] << " ";
    std::cout << "\nPend: ";
    for (size_t i = 0; i < Pend.size(); i++)
        std::cout << Pend[i] << " ";
    std::cout << std::endl;

    for (size_t i = 0; i < jacobList.size(); i++)
    {
        int valueToInsert = Pend[jacobList[i]];
        count += std::log2(Main.size());
        std::vector<unsigned int>::iterator posInMain = std::lower_bound(Main.begin(), Main.end(), valueToInsert);
        Main.insert(posInMain, valueToInsert);
    }
    listNb = Main;
}

// void PmergeMe::mergeSort(std::vector<unsigned int>& listNb, size_t& count) {
//     if (listNb.size() < 2)
//         return;

//     std::vector<unsigned int> Main;
//     std::vector<unsigned int> Pend;
//     size_t len = listNb.size();
//     bool Odd = (len % 2 != 0);
//     unsigned int last = 0;

//     if (Odd) {
//         last = listNb.back();
//         listNb.pop_back();
//         len--;
//     }

//     // Étape 1 : créer les paires et séparer max/min
//     for (size_t i = 0; i < len; i += 2) {
//         unsigned int a = listNb[i];
//         unsigned int b = listNb[i + 1];
//         count++; // Comparaison a vs b
//         if (a > b) {
//             Main.push_back(a);
//             Pend.push_back(b);
//         } else {
//             Main.push_back(b);
//             Pend.push_back(a);
//         }
//     }

//     // Étape 2 : trier les max (Main) récursivement
//     mergeSort(Main, count);

//     // Étape 3 : insérer Pend[0]
//     if (!Pend.empty()) {
//         std::vector<unsigned int>::iterator pos = std::lower_bound(Main.begin(), Main.end(), Pend[0]);
//         count += std::log2(Main.size());
//         Main.insert(pos, Pend[0]);
//     }

//     // Ajouter l'élément impair à la fin de Pend (comme dans ta version)
//     if (Odd)
//         Pend.push_back(last);

//     // Étape 4 : générer ordre Jacobsthal, en sautant le premier index (déjà inséré)
//     std::vector<int> jacobOrder = generateJacobsthalOrder(Pend.size());
//     if (!jacobOrder.empty())
//         jacobOrder.erase(jacobOrder.begin());

//     // Étape 5 : insérer les Pend restants
//     for (size_t i = 0; i < jacobOrder.size(); ++i) {
//         size_t idx = jacobOrder[i];
//         if (idx >= Pend.size())
//             continue;
//         unsigned int valueToInsert = Pend[idx];
//         std::vector<unsigned int>::iterator pos = std::lower_bound(Main.begin(), Main.end(), valueToInsert);
//         count += std::log2(Main.size());
//         Main.insert(pos, valueToInsert);
//     }

//     // Résultat final
//     listNb = Main;
// }
