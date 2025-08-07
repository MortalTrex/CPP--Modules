#include "BitcoinExchange.hpp"

// ------------- Canonical Form ----------------

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(std::string filename) : _inputFile(filename){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : _inputFile(src._inputFile){}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cpy)
{
    if (this != &cpy)
        this->_inputFile = cpy._inputFile;
    return *this;
}

BitcoinExchange::~BitcoinExchange(){}

// ------------- UTILS ---------------- 

std::string ft_trim(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");
    
    if (start == std::string::npos)
        return "";
    return str.substr(start, end - start + 1);
}

// ------------- PARSING ----------------

bool checkFileFormat(const std::string filename, const std::string format)
{
    if (filename.size() >= 4 && filename.substr(filename.size() - 4) == format)
        return true;
    return false;
}

bool isYearValid(int year)
{
    if (year < 2009 || year >= 2026)
        return false;
    return true;
}

bool isMonthValid(int month)
{
    if (month < 1 || month > 12)
        return false;
    return true;
}

bool isDayValid(int year, int month, int day)
{
    if (day < 1 || day > 31)
        return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            if (day > 29)
                return false;
        }
        else
        {
            if (day > 28)
                return false;
        }
    }
    return true;
}

bool isBtcValueValid(const std::string &btcValue)
{
    if (btcValue[0] == '-')
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (btcValue.find_first_not_of("0123456789.") != std::string::npos)
    {
        std::cerr << "Error: not a valid number." << std::endl;
        return false;
    }
    if (btcValue.find('.') != std::string::npos)
    {
        if (btcValue.find('.') != btcValue.rfind('.'))
        {
            std::cerr << "Error: too many decimal points." << std::endl;
            return false;
        }
        if (btcValue.find('.') == 0 || btcValue.find('.') == btcValue.size() - 1)
        {
            std::cerr << "Error: value cannot start or end with a decimal point." << std::endl;
            return false;
        }
    }
    if (btcValue.size() > 10 || (btcValue.size() == 10 && btcValue > "2147483647"))
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

bool isValidLine(const std::string &date, const std::string &value)
{
    if (date.empty() || value.empty())
    {
        std::cerr << "Error: empty date or value." << std::endl;
        return false;
    }
    // Check date format
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
    {
        std::cerr << "Error: bad date format => " << date << std::endl;
        return false;
    }
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());
    if (!isYearValid(year) || !isMonthValid(month) || !isDayValid(year, month, day))
    {
        std::cerr << "Error: bad date => " << date << std::endl;
        return false;
    }
    // Check value format
    if (!isBtcValueValid(value))
        return false;
    return true;
}

// ------------- CORE ----------------

void BitcoinExchange::createExchangeRatesMap()
{
    std::string::size_type  commaPos;
    std::string             line;
    std::string             date;
    std::string             valueStr;
    float                   value;
    std::ifstream           data("data.csv");
    if (!data.is_open())
        throw std::runtime_error("Error: could not open data file");
    
    std::getline(data, line);
    if (line != "date,exchange_rate")
        throw std::runtime_error("Error: first line must be 'date,exchange_rate'");
    while (std::getline(data, line))
    {
        if (line.empty())
            continue ;
        commaPos = line.find(',');
        if (commaPos == std::string::npos)
            throw std::runtime_error("Error: bad input format in data file");
        date = ft_trim(line.substr(0, commaPos));
        valueStr = line.substr(commaPos + 1);
        if (!isValidLine(date, valueStr))
            throw std::invalid_argument("Wrong data.csv");
        std::stringstream ss(valueStr);
        if (ss >> value)
            _exchangeRates[date] = value;
    }
    data.close();
}

void BitcoinExchange::displayResult(const std::string &date, const std::string &value)
{
    std::stringstream ss(value);
    float f_value;
    ss >> f_value;

    std::map<std::string, float>::iterator it = _exchangeRates.lower_bound(date);

    if (it == _exchangeRates.end() || it->first != date)
    {
        if (it == _exchangeRates.begin())
        {
            std::cerr << "Error: date not exist => " << date << std::endl;
            return;
        }
        --it;
    }
    std::cout << date << " => " << value << " == " << f_value * it->second << std::endl;
}


void BitcoinExchange::execute()
{
    std::string             line;
    std::string             date;
    std::string             value;
    size_t                  pipePos;
    
    createExchangeRatesMap();
    
    std::ifstream           input(_inputFile.c_str());
    if (!input.is_open())
        throw std::runtime_error("Error: could not open file " + _inputFile);
    if (!checkFileFormat(_inputFile, ".txt"))
        throw std::runtime_error("Wrong format of file");
    if (_inputFile.empty())
        throw std::runtime_error("Error: filename is empty");
    std::getline(input, line);
    if (line != "date | value")
        throw std::runtime_error("Error: first line must be 'date | value'");
    while (std::getline(input, line))
    {
        if (line.empty())
            continue ;
        pipePos = line.find("|");
        if (pipePos == std::string::npos || pipePos == 0 || pipePos == line.size() - 1)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        date = ft_trim(line.substr(0, pipePos));
        value = ft_trim(line.substr(pipePos + 1));
        if (!isValidLine(date, value))
            continue;
        displayResult(date, value);
    }
    input.close();
}
