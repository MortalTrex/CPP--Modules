#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <cstdlib>
#include <string>
#include <map>

class BitcoinExchange
{
    private:
        std::string _inputFile;
        std::map <std::string, float> _exchangeRates;
        std::map <std::string, int> _input;
    
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string filename);
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &cpy);
        ~BitcoinExchange();
        
        void createExchangeRatesMap();
        void createInputMap();
        float getBtcValue();

        void execute();
};

#endif