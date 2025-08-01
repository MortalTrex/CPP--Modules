#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>

class BitcoinExchange
{
    private:
        std::string _filename;
        std::string _date;
        std::string _btcValue;
        std::map <std::string, float> _exchangeRates;
    
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string filename);
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &cpy);
        ~BitcoinExchange();
        
        bool isYearValid();
        bool isMonthValid();
        bool isDayValid();
        void createExchangeRatesMap();
        bool parseLine(std::string line);
        void execute();
        void readExchangeRatesMap();
        float getBtcValue();
};

#endif