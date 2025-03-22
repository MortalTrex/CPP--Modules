#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include "phonebook.hpp"
#include "contact.hpp"

static bool verif_phonenumber(std::string str)
{
    int i = 0;
    while (str[i])
    {
        if (isdigit(str[i]) == false)
        {
            std::cout << "\033[1;31mInvalid phone number\033[0m" << std::endl;
            return false;
        }
        i++;
    }
    return true;
}

static void print_info(std::string info)
{
    if (info.length() > 10)
        std::cout << std::setw(10) << info.substr(0, 9) + "." << " |";
    else
        std::cout << std::setw(10) << info << " |";
}

Phonebook::Phonebook()
{
}

Phonebook::~Phonebook()
{
}
void Phonebook::set_Contacts(int i)
{
    _contacts[i].setIndex(i + 1);
    _contacts[i].setFirstName("");
    _contacts[i].setLastName("");
    _contacts[i].setNickname("");
    _contacts[i].setPhoneNumber("");
    _contacts[i].setDarkestSecret("");
}

void Phonebook::print_table()
{
    int i = 0;
    std::cout << "\033[1;33m+------------+------------+------------+------------+\033[0m" << std::endl;
    std::cout << "\033[1;33m| " << std::setw(10) << "INDEX" << " | " << std::setw(10) << "FIRSTNAME" << " | " << std::setw(10) << "LASTNAME" << " | " << std::setw(10) << "NICKNAME" << " |\033[0m" << std::endl;
    std::cout << "\033[1;33m+------------+------------+------------+------------+\033[0m" << std::endl;
    while (i < 8)
    {
        if (!_contacts[i].getFirstName().empty())
        {
            std::cout << "| " << std::setw(10) << _contacts[i].getIndex() << " | ";
            print_info(_contacts[i].getFirstName());
            print_info(_contacts[i].getLastName());
            print_info(_contacts[i].getNickname());
            std::cout << std::endl;
        }
        i++;
    }
    std::cout << "\033[1;33m+------------+------------+------------+------------+\033[0m" << std::endl;
}

void Phonebook::search_contact()
{
    int i = 0;
    std::string search_index;

    std::cout << "\033[1;34mEnter the index of the contact [1 to 8]: \033[0m";
    std::getline(std::cin, search_index);
    if (atoi(search_index.c_str()) < 1 || atoi(search_index.c_str()) > 8)
    {
        std::cout << "\033[1;31mInvalid index\033[0m" << std::endl;
        return;
    }
    while (i < 8)
    {
        if (_contacts[i].getIndex() == atoi(search_index.c_str()))
        {
            if (_contacts[i].getFirstName().empty())
            {
                std::cout << "\033[1;31mContact not found\033[0m" << std::endl;
                return;
            }
            std::cout << "First name: " << _contacts[i].getFirstName() << std::endl;
            std::cout << "Last name: " << _contacts[i].getLastName() << std::endl;
            std::cout << "Nickname: " << _contacts[i].getNickname() << std::endl;
            std::cout << "Phone number: " << _contacts[i].getPhoneNumber() << std::endl;
            break;
        }
        i++;
    }
}

void Phonebook::add_contact(int i)
{
    while (this->_contacts[i].getFirstName().empty())
    {
        std::cout << "Enter first name: ";
        std::string firstName;
        std::getline(std::cin, firstName);
        if (!std::cin)
            return;
        this->_contacts[i].setFirstName(firstName);
    }
    while (this->_contacts[i].getLastName().empty())
    {
        std::cout << "Enter last name: ";
        std::string lastName;
        std::getline(std::cin, lastName);
        if (!std::cin)
            return;
        this->_contacts[i].setLastName(lastName);
    }
    while (this->_contacts[i].getNickname().empty())
    {
        std::cout << "Enter nickname: ";
        std::string nickname;
        std::getline(std::cin, nickname);
        if (!std::cin)
            return;
        this->_contacts[i].setNickname(nickname);
    }
    while (this->_contacts[i].getPhoneNumber().empty() || verif_phonenumber(this->_contacts[i].getPhoneNumber()) == false)
    {
        std::cout << "Enter phone number: ";
        std::string phoneNumber;
        std::getline(std::cin, phoneNumber);
        if (!std::cin)
            return;
        this->_contacts[i].setPhoneNumber(phoneNumber);
    }
    while (this->_contacts[i].getDarkestSecret().empty())
    {
        std::cout << "Enter darkest secret: ";
        std::string darkestSecret;
        std::getline(std::cin, darkestSecret);
        if (!std::cin)
            return;
        this->_contacts[i].setDarkestSecret(darkestSecret);
    }
}
