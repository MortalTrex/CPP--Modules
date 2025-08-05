#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <cstdlib>
#include <string>
#include <algorithm> 
#include <map>
#include <iomanip>

class BitcoinExchange
{
    private:
        std::string _inputFile;
        std::map <std::string, float> _exchangeRates;
    
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string filename);
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &cpy);
        ~BitcoinExchange();
        
        void createExchangeRatesMap();
        void displayResult(const std::string &date, const std::string &value);

        void execute();
};

#endif