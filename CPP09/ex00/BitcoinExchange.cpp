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

int daysFebruary(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 29;
    return 28;
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
    if (year < 2009 || year > 2023)
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

    if (date == "02")
    {
        if (intDay < 1 || intDay > daysFebruary(atoi(date.c_str())))
            return false;
    }
    else if (date == "04" || date == "06" || date == "09" || date == "11")
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


// float BitcoinExchange::getBtcValue()
// {
//     std::string year = _date[0];
//     std::string month = _date[1];
//     std::string day = _date[2];
//     float btc;
//     bool found = false;

//     for (std::map<std::string, float>::iterator it = _exchangeRates.begin(); it != _exchangeRates.end(); ++it)
//     {
//         if (it->first.substr(0, 4) == year)
//         {
//             if (it->first.substr(5, 2) == month)
//             {
//                 if (it->first.substr(8, 2) >= day)
//                     found = true;
//             }
//         }
//         if (found)
//         {
//             std::stringstream ss(_btcValue);
//             if (ss >> btc)
//                 return btc * it->second;
//         }
//     }
//     return 0.0f;
// }


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
        if (line != "date | value")
            std::cout << date << " | " << value << std::endl;
    }
    input.close();
}