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
    //utiliser isNaNx
    char *ptr;
    double result = strtod(literal.c_str(), &ptr);

    if (!std::isprint(result))
        std::cout << "char : " << "Non displayable" << std::endl;
    else if (std::isnan(result))
        std::cout << "char : " << "impossible" << std::endl;
    else if (!std::isnan(result))
        std::cout << "char: " << static_cast<char>(result) << std::endl;

    if (std::isnan(result))
        std::cout << "int : " << "impossible" << std::endl;
    else if (!std::isnan(result))
        std::cout << "int : " << static_cast<int>(result) << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(result) << "f" << std::endl;

    std::cout << "double: " << result << std::endl;
}