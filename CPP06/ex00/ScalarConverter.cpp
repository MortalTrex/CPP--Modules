#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
   
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
   
}

void ScalarConverter::convert(const std::string &literal)
{
    std::cout << "Converting literal: " << literal << std::endl;

    std::cout << "char: ";
    std::cout << std::endl;
    std::cout << "int : ";
    std::cout << std::endl;
    std::cout << "float: ";
    std::cout << std::endl;
    std::cout << "double: ";
    std::cout << std::endl;
}