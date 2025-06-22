#include "ScalarConverter.hpp"

// Canonical form of ScalarConverter class //

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


// Functions to display the converted values //

void displayChar(double result)
{
    if (std::isnan(result) || result < 0 || result > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(result)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(result) << "'" << std::endl;
}

void displayInt(double result)
{
    if (std::isnan(result) || result < static_cast<double>(INT_MIN) || result > static_cast<double>(INT_MAX))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(result) << std::endl;
}

void displayFloat(double result)
{
    if (std::isnan(result) || result < static_cast<double>(FLOAT_MIN) || result > static_cast<double>(FLOAT_MAX))
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(result) << "f" << std::endl;
}

void displayDouble(double result)
{
    if (std::isnan(result) || result < static_cast<double>(DOUBLE_MIN) || result > static_cast<double>(DOUBLE_MAX))
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << std::fixed << std::setprecision(1) << result << std::endl;
}


// Mandatory conversion method //

void ScalarConverter::convert(const std::string &literal)
{
    if (literal.length() == 1 && !std::isdigit(literal[0]))
    {
        std::cout << "char: '" << literal[0]<< "'" << std::endl;
        std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(literal[0]) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(literal[0]) << std::endl;
        return;
    }
    
    char *ptr;
    double result;

    if (literal == "nan" || literal == "nanf")
        result = std::numeric_limits<double>::quiet_NaN();
    else if (literal == "inf" || literal == "inff" || literal == "+inf" || literal == "+inff")
        result = std::numeric_limits<double>::infinity();
    else if (literal == "-inf" || literal == "-inff")
        result = -std::numeric_limits<double>::infinity();
    else
    {
        std::cout << "ICII" << std::endl;
        result = strtod(literal.c_str(), &ptr);
        if (ptr == literal.c_str())
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
    }
    displayChar(result);
    displayInt(result);
    displayFloat(result);
    displayDouble(result);
}