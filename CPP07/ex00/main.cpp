#include "whatever.hpp"

struct Data
{
    int value;
    std::string word;
};

int main()
{
    std::cout << max(6.0, 3.0) << std::endl;
    std::cout << max(3, 3) << std::endl;

    std::cout << min(6.0, 3.0) << std::endl;

    int a = 4;
    int b = 5;
    swap(a, b);
    std::cout << "a = " << a << " b = " << b << std::endl;

    std::string word1 = "premier";
    std::string word2 = "deuxieme";
    swap(word1, word2);
    std::cout << "1 = " << word1 << " 2 = " << word2 << std::endl;

    // Test complex type
    Data data1;
    Data data2;
    data1.value = 42;
    data1.word = "Up";
    data2.value = 84;
    data2.word = "data2";

    swap(data1, data2);
    std::cout << "data1 value = " << data1.value << " data1 word = " << data1.word << std::endl;
    std::cout << "data2 value = " << data2.value << " data2 word = " << data2.word << std::endl;
}