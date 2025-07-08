#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <exception>

class BitcoinExchange {
    private:
        std::string _filename;
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string filename);
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &cpy);
        ~BitcoinExchange();

        void execute();
        bool parseLine(std::string line);

};

#endif