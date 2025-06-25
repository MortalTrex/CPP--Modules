#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cmath>
#include <stdexcept>
#include <limits>

#define INT_MAX std::numeric_limits<int>::max()
#define INT_MIN std::numeric_limits<int>::min()
#define FLOAT_MAX std::numeric_limits<float>::max()
#define FLOAT_MIN -std::numeric_limits<float>::max()
#define DOUBLE_MAX std::numeric_limits<double>::max()
#define DOUBLE_MIN -std::numeric_limits<double>::max()


class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
    public:
        static void convert(const std::string &literal);
};
void displayChar(double result);
void displayInt(double result);
void displayFloat(double result);
void displayDouble(double result);
bool isWrongInput(std::string &literal);

#endif