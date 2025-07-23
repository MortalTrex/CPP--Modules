#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc < 2)
            throw std::invalid_argument("Any values");
        std::vector<int> nb;
        for (int i = 1; i < argc; i++)
        {
            for (int j = 0; argv[i][j]; j++)
                if (!isdigit(argv[i][j]))
                    throw std::invalid_argument("Wrong input");
            nb.push_back(atoi(argv[i]));
        }
        PmergeMe merge(nb);
        merge.executeMerge();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
    }
    
}