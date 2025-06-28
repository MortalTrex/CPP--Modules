#include <iostream>
#include "Array.hpp"

#define MAX_VAL 7

struct Data
{
    int value;
    std::string word;
};

int main(int, char**)
{
    Array<int> empty;
    const Array<int> constNumber(MAX_VAL);
    std::cout << constNumber[0] << std::endl;

    Array<int> numbers(MAX_VAL);
    Array<float> numbersFloat(MAX_VAL);
    Array<double> numbersDouble(MAX_VAL);
    Array<std::string> words(MAX_VAL);
    Array<Data> data(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));

    // INSERT VALUES
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        const double valueD = rand();
        const float valueF = rand();
        numbers[i] = value;
        numbersFloat[i] = valueF;
        numbersDouble[i] = valueD;
        data[i].value = 42;
        data[i].word = "Up";
        words[i] = "Salut";
        mirror[i] = value;
    }

    // CHECK COPY
    Array<int> tmp = numbers;
    Array<int> test(tmp);

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
        if (test[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    // TESTS ERROR OUTSIDE ARRAY
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "Test max number" << std::endl;
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // DISPLAY INFORMATIONS
    try
    {
        std::cout << "Print numbers[i]" << std::endl;
        for (int i = 0; i < MAX_VAL; i++)
        {
            //std::cout << empty[i] << std::endl;
            std::cout << "\033[31m" << "number : " << numbers[i] << "\033[0m" << std::endl;
            std::cout << "\033[32m" << "float : " << numbersFloat[i] << "\033[0m" << std::endl;
            std::cout << "\033[34m" << "double : " << numbersDouble[i] << "\033[0m" << std::endl;
            std::cout << "\033[35m" << "string : " << words[i] << "\033[0m" << std::endl;
            std::cout << "\033[30m" << "data : " << data[i].value << data[i].word << "\033[0m" << std::endl; 
        }
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}