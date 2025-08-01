#include "BitcoinExchange.hpp"

// ------------- Canonical Form ----------------

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


// ------------- UTILS ---------------- 

std::vector<std::string> ft_split(const std::string& str, char delimiter)
{
    std::vector<std::string>    result;
    std::string                 value;
    std::stringstream           ss(str);

    while (std::getline(ss, value, delimiter))
        result.push_back(value);
    return result;
}

std::string ft_trim(const std::string& s)
{
    size_t start = s.find_first_not_of(" \t\n\r");
    size_t end = s.find_last_not_of(" \t\n\r");

    if (start == std::string::npos) return "";
    return s.substr(start, end - start + 1);
}

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
            else
                std::cerr << "Warning: invalid float in line: " << line << std::endl;
        }
    }
    data.close();
}

void BitcoinExchange::readExchangeRatesMap()
{
    std::map<std::string, float>::const_iterator it;

    for (it = _exchangeRates.begin(); it != _exchangeRates.end(); ++it)
    {
        std::cout << "Date: " << it->first << " | Rate: " << it->second << std::endl;
    }
}

float BitcoinExchange::getBtcValue()
{
    std::string year = _date[0];
    std::string month = _date[1];
    std::string day = _date[2];
    float btc;
    bool found = false;

    for (std::map<std::string, float>::iterator it = _exchangeRates.begin(); it != _exchangeRates.end(); ++it)
    {
        if (it->first.substr(0, 4) == year)
        {
            if (it->first.substr(5, 2) == month)
            {
                if (it->first.substr(8, 2) >= day)
                    found = true;
            }
        }
        if (found)
        {
            std::stringstream ss(_btcValue);
            if (ss >> btc)
                return btc * it->second;
        }
    }
    return 0.0f;
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


bool BitcoinExchange::isYearValid()
{
    for (size_t i = 0; i < _date[0].size(); i++)
    {
        if (!isdigit(_date[0][i]))
            return false;
    }
    return true;
}

bool BitcoinExchange::isMonthValid()
{
    if (_date[1].size() != 2)
        return false;
    int intMonth = atoi(_date[1].c_str());

    if (intMonth < 1 || intMonth > 12)
        return false;
    return true;
}

bool BitcoinExchange::isDayValid()
{
    if (_date[2].size() != 2)
        return false;
    int intDay = atoi(_date[2].c_str());

    if (_date[1] == "02")
    {
        if (intDay < 1 || intDay > daysFebruary(atoi(_date[0].c_str())))
            return false;
    }
    else if (_date[1] == "04" || _date[1] == "06" || _date[1] == "09" || _date[1] == "11")
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

bool BitcoinExchange::parseLine(std::string line)
{
    // SEPARATE DATE AND VALUE
    std::string::size_type pipePos = line.find('|');
    if (pipePos != std::string::npos)
    {
        _btcValue = ft_trim(line.substr(pipePos + 1));
        if (!checkBtcValue(_btcValue))
            return false;
        line = line.substr(0, pipePos);
    }
    else
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }

    // DATE VALIDATION
    _date = ft_split(ft_trim(line), '-');
    if (_date.size() != 3)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }

    if (line == "date | value")
        return true;
    else if (isYearValid() && isMonthValid() && isDayValid())
    {
        std::cout << _date[0] + "-" + _date[1] + "-" + _date[2] + " => " + _btcValue + " = " << getBtcValue() << std::endl;
    }
    else
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }
    return true;
}



// ------------- EXECUTE ----------------

void BitcoinExchange::execute()
{
    std::string line;
    
    std::ifstream input(_filename.c_str());
    if (!input.is_open())
        throw std::runtime_error("Error: could not open file " + _filename);
    if (!checkFileFormat(_filename, ".txt"))
        throw std::runtime_error("Wrong format of file");
    if (_filename.empty())
        throw std::runtime_error("Error: filename is empty");
    createExchangeRatesMap();

    while(std::getline(input, line))
        parseLine(line);
    input.close();
}