#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc < 2)
            throw std::invalid_argument("Any values");
        std::vector<unsigned int> Vnb;
        std::deque<unsigned int> Dnb;

        for (int i = 1; i < argc; i++)
        {
            for (int j = 0; argv[i][j]; j++)
                if (!isdigit(argv[i][j]))
                    throw std::invalid_argument("Wrong input");
            Vnb.push_back(atoi(argv[i]));
            Dnb.push_back(atoi(argv[i]));
        }

        // VECTOR
        // Print before merge
        std::cout << "\033[31mBefore: ";
        for (size_t i = 0 ; i < Vnb.size() - 1 ; i++)
        {
            std::cout << Vnb[i] << " ";
        }
        std::cout << Vnb[Vnb.size() - 1] << "\033[0m" << std::endl;

        clock_t start = clock();

        PmergeMe merge;
        merge.mergeSort(Vnb);
        
        // CLOCK PRINT
        clock_t end = clock();
        std::cout << "\033[34mTime to process a range of " << Vnb.size() << " elements with std::vector : ";
        std::cout << static_cast<double>(end - start) * 1e6 / CLOCKS_PER_SEC << "us\033[0m" << std::endl;

        
        // Print result
        std::cout << "\033[32mAfter: ";
        for (size_t i = 0 ; i < Vnb.size() - 1; i++)
        {
            std::cout << Vnb[i] << " ";
        }
        std::cout << Vnb[Vnb.size() - 1] << "\033[0m" << std::endl;

        start = clock();
        merge.mergeSort(Dnb);
        end = clock();
        std::cout << "\033[34mTime to process a range of " << Vnb.size() << " elements with std::deque : ";
        std::cout << static_cast<double>(end - start) * 1e6 / CLOCKS_PER_SEC << "us\033[0m" << std::endl;

    }


    catch(const std::exception& e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
    }
}