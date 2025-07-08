#include "BitcoinExchange.hpp"

// Canonical Form

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(std::string filename) : _filename(filename){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : _filename(src._filename){}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cpy)
{
    if (this != &cpy)
        this->_filename = cpy._filename;
    return *this;
}

BitcoinExchange::~BitcoinExchange(){}



// Parsing 

bool checkFormat(const std::string filename, const std::string format)
{
    if (filename.size() >= 4 && filename.substr(filename.size() - 4) == format)
        return true;
    return false;
}

bool BitcoinExchange::parseLine(std::string line)
{
    int countDash = 0;
    for (long unsigned int i = 0 ; i < line.size() ; i++)
    {
        // Parse Year
        if (countDash == 0)
        {
            if (!isdigit(line[i]) && line[i] != '-')
            {
                std::cerr << "Error : Wrong year format" << std::endl;
                return false;
            }
        }

        // Parse Month
        else if (countDash == 1)
        {
            if (!isdigit(line[i]) && line[i] != '-')
            {
                std::cerr << "Error : Wrong month format" << std::endl;
                return false;
            }
        }

        // Parse Day
        else if (countDash == 2)
        {
            if (!isdigit(line[i]) && line[i] != '-' && line[i] != '|' && line[i] != ' ')
            {
                std::cerr << "Error : Wrong day format" << std::endl;
                return false;
            }
        }
        if (line[i] == '-')
            countDash++;
    }
    return true;
}



// Main function

void BitcoinExchange::execute()
{
    // Inputs
    std::string line;
    std::ifstream input(_filename.c_str());
    if (!input.is_open())
        throw std::runtime_error("Error: could not open file " + _filename);
    if (!checkFormat(_filename, ".txt"))
        throw std::runtime_error("Wrong format of file");
    
    std::ifstream data("data.csv");
    if (!data.is_open())
        throw std::runtime_error("Error: could not open data file");

    // Main Loop
    while(std::getline(input, line))
    {
        if (line != "date | value" && parseLine(line))
        {
            std::cout << line << std::endl;

        }
    }
    input.close();
    data.close();
}