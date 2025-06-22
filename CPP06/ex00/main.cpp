#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    // Check if scalar converter is not instantiated
    // ScalarConverter converter;
    // ScalarConverter converter2(converter);
    // converter = converter2;

    if (argc != 2)
    {
        std::cerr << "Bad arguments" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}