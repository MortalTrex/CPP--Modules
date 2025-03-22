#include "contact.hpp"
#include "phonebook.hpp"
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>

static bool verif_phonenumber(std::string str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            std::cout << "\033[1;31mInvalid phone number\033[0m" << std::endl;
            return (false);
        }
    }
    return (true);
}

static void print_info(std::string info)
{
    if (info.length() > 10)
        std::cout << std::setw(10) << info.substr(0, 9) + "."
                  << " |";
    else
        std::cout << std::setw(10) << info << " |";
}

Phonebook::Phonebook()
{
    for (int i = 0; i < 8; i++)
        set_Contacts(i);
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
    std::cout << "\033[1;33m+------------+------------+------------+------------+\n"
              << "| " << std::setw(10) << "INDEX"
              << " | " << std::setw(10) << "FIRSTNAME"
              << " | " << std::setw(10) << "LASTNAME"
              << " | " << std::setw(10) << "NICKNAME"
              << " |\n"
              << "+------------+------------+------------+------------+\033[0m" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        if (!_contacts[i].getFirstName().empty())
        {
            std::cout << "| " << std::setw(10) << _contacts[i].getIndex() << " | ";
            print_info(_contacts[i].getFirstName());
            print_info(_contacts[i].getLastName());
            print_info(_contacts[i].getNickname());
            std::cout << std::endl;
        }
    }
    std::cout << "\033[1;33m+------------+------------+------------+------------+\033[0m" << std::endl;
}

void Phonebook::search_contact()
{
    int index_Contact;

    std::string input_index;
    std::cout << "\033[1;34mEnter the index of the contact [1 to 8]: \033[0m";
    std::getline(std::cin, input_index);
    index_Contact = std::atoi(input_index.c_str()) - 1;
    if (index_Contact < 0 || index_Contact > 7)
    {
        std::cout << "\033[1;31mInvalid index\033[0m" << std::endl;
        return;
    }
    if (_contacts[index_Contact].getFirstName().empty())
    {
        std::cout << "\033[1;31mContact not found\033[0m" << std::endl;
        return;
    }
    std::cout << "First name: " << _contacts[index_Contact].getFirstName() << std::endl;
    std::cout << "Last name: " << _contacts[index_Contact].getLastName() << std::endl;
    std::cout << "Nickname: " << _contacts[index_Contact].getNickname() << std::endl;
    std::cout << "Phone number: " << _contacts[index_Contact].getPhoneNumber() << std::endl;
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
    while (this->_contacts[i].getPhoneNumber().empty() || !verif_phonenumber(this->_contacts[i].getPhoneNumber()))
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
