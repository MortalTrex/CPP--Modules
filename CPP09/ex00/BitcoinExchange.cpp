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

std::string ft_trim(const std::string& s)
{
    size_t start = s.find_first_not_of(" \t\n\r");
    size_t end = s.find_last_not_of(" \t\n\r");
    
    if (start == std::string::npos) return "";
    return s.substr(start, end - start + 1);
}

bool daysFebruary(std::string year, std::string month, std::string day)
{
    int i_year = atoi(year.c_str());
    int i_month = atoi(month.c_str());
    int i_day = atoi(day.c_str());

    if (i_month == 2)
    {
        if ((i_year % 4 == 0 && i_year % 100 != 0) || (i_year % 400 == 0))
        {
            if (i_day >= 1 && i_day <= 29)
                return true;
            else
                return false;
        }
        else
        {
            if (i_day >= 1 && i_day <= 28)
                return true;
            else
                return false;
        }
    }
    return true;
}

// ------------- PARSING ----------------

bool checkFileFormat(const std::string filename, const std::string format)
{
    if (filename.size() >= 4 && filename.substr(filename.size() - 4) == format)
        return true;
    return false;
}

bool isYearValid(const std::string &date)
{
    if (date.size() != 4)
        return false;
    if (date.find_first_not_of("0123456789") != std::string::npos)
        return false;
    
    int year = atoi(date.c_str());
    if (year < 2009 || year > 2026)
        return false;
    
    return true;
}

bool isMonthValid(std::string &date)
{
    if (date.size() != 2)
        return false;
    int intMonth = atoi(date.c_str());

    if (intMonth < 1 || intMonth > 12)
        return false;
    return true;
}

bool isDayValid(std::string &date)
{
    if (date.size() != 2)
        return false;
    int intDay = atoi(date.c_str());

    if (date == "04" || date == "06" || date == "09" || date == "11")
    {
        if (intDay < 1 || intDay > 30)
            return false;
    }
    else
    {
        if (intDay < 1 || intDay > 31)
            return false;
    }
    return true;
}

bool checkBtcValue(const std::string &btcValue)
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
    if (btcValue.size() > 10 || (btcValue.size() == 10 && btcValue > "2147483647"))
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}


void BitcoinExchange::displayResult(const std::string &date, const std::string &value)
{
    float f_value = std::atof(value.c_str());

    std::map<std::string, float>::iterator it = this->_exchangeRates.lower_bound(date);

    if (it->first != date)
    {
        if (it == _exchangeRates.begin())
        {
            std::cerr << "error: date not exist" << std::endl;
            return ;
        }
        it--;
    }
    std::cout << std::fixed << std::setprecision(2) << date << " => " << f_value * it->second << std::endl;
}


// ------------- MAP CREATION ----------------

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
    while (std::getline(data, line))
    {
        commaPos = line.find(',');
        if (commaPos != std::string::npos)
        {
            date = line.substr(0, commaPos);
            valueStr = line.substr(commaPos + 1);

            std::stringstream ss(valueStr);
            if (ss >> value)
                _exchangeRates[date] = value;
        }
    }
    data.close();
}

bool parseDateValue(const std::string &date, const std::string &value)
{
    if (date.empty() || value.empty())
    {
        std::cerr << "Error: empty date or value." << std::endl;
        return false;
    }
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
    {
        std::cerr << "Error: bad date format => " << date << std::endl;
        return false;
    }
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);
    if (!isYearValid(year) || !isMonthValid(month) || !isDayValid(day) || !daysFebruary(year, month, day))
    {
        std::cerr << "Error: bad date => " << date << std::endl;
        return false;
    }
    if (!checkBtcValue(value))
        return false;
    return true;
}

void BitcoinExchange::execute()
{
    std::string             line;
    std::string             valueStr;
    std::string             date;
    std::string             value;
    std::ifstream           input(_inputFile.c_str());
    size_t                  pipePos;

    createExchangeRatesMap();

    if (!input.is_open())
        throw std::runtime_error("Error: could not open file " + _inputFile);
    if (!checkFileFormat(_inputFile, ".txt"))
        throw std::runtime_error("Wrong format of file");
    if (_inputFile.empty())
        throw std::runtime_error("Error: filename is empty");
    while (std::getline(input, line))
    {
        if (line == "date | value" || line.empty())
            continue ;
        pipePos = line.find("|");
        if (pipePos == std::string::npos || pipePos == 0 || pipePos == line.size() - 1)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        date = ft_trim(line.substr(0, pipePos));
        value = ft_trim(line.substr(pipePos + 1));
        if (!parseDateValue(date, value))
            continue;
        displayResult(date, value);
    }
    input.close();
}
