#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include "phonebook.hpp"
#include "contact.hpp"

static bool verif_phonenumber(std::string str)
{
    //int i = 0;
    (void)str;
    // while (str[i])
    // {
    //     if (isdigit(str[i]) == false)
    //     {
    //         std::cout << "\033[1;31mInvalid phone number\033[0m" << std::endl;
    //         return false;
    //     }
    //     i++;
    // }
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
void Phonebook::set_Contacts()
{
    int i = 0;
    while (i < 8)
    {
        contacts[i].setIndex(i + 1);
        contacts[i].setFirstName("");
        contacts[i].setLastName("");
        contacts[i].setNickname("");
        contacts[i].setPhoneNumber("");
        contacts[i].setDarkestSecret("");
        i++;
    }
}

void Phonebook::print_table()
{
    int i = 0;
    std::cout << "\033[1;33m+------------+------------+------------+------------+\033[0m" << std::endl;
    std::cout << "\033[1;33m| " << std::setw(10) << "INDEX" << " | " << std::setw(10) << "FIRSTNAME" << " | " << std::setw(10) << "LASTNAME" << " | " << std::setw(10) << "NICKNAME" << " |\033[0m" << std::endl;
    std::cout << "\033[1;33m+------------+------------+------------+------------+\033[0m" << std::endl;
    while (i < 8)
    {
        if (!contacts[i].getFirstName().empty())
        {
            std::cout << "| " << std::setw(10) << contacts[i].getIndex() << " | ";
            print_info(contacts[i].getFirstName());
            print_info(contacts[i].getLastName());
            print_info(contacts[i].getNickname());
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
        if (contacts[i].getIndex() == atoi(search_index.c_str()))
        {
            if (contacts[i].getFirstName().empty())
            {
                std::cout << "\033[1;31mContact not found\033[0m" << std::endl;
                return;
            }
            std::cout << "First name: " << contacts[i].getFirstName() << std::endl;
            std::cout << "Last name: " << contacts[i].getLastName() << std::endl;
            std::cout << "Nickname: " << contacts[i].getNickname() << std::endl;
            std::cout << "Phone number: " << contacts[i].getPhoneNumber() << std::endl;
            break;
        }
        i++;
    }
}

void Phonebook::add_contact(int i)
{
    while (this->contacts[i].getFirstName().empty())
    {
        std::cout << "Enter first name: ";
        std::string firstName;
        std::getline(std::cin, firstName);
        this->contacts[i].setFirstName(firstName);
        if (std::cin.eof())
            return;
    }
    while (this->contacts[i].getLastName().empty())
    {
        std::cout << "Enter last name: ";
        std::string lastName;
        std::getline(std::cin, lastName);
        this->contacts[i].setLastName(lastName);
        if (std::cin.eof())
            return;
    }
    while (this->contacts[i].getNickname().empty())
    {
        std::cout << "Enter nickname: ";
        std::string nickname;
        std::getline(std::cin, nickname);
        this->contacts[i].setNickname(nickname);
        if (std::cin.eof())
            return;
    }
    while (this->contacts[i].getPhoneNumber().empty() || verif_phonenumber(this->contacts[i].getPhoneNumber()) == false)
    {
        std::cout << "Enter phone number: ";
        std::string phoneNumber;
        std::getline(std::cin, phoneNumber);
        this->contacts[i].setPhoneNumber(phoneNumber);
        if (std::cin.eof())
            return;
    }
    while (this->contacts[i].getDarkestSecret().empty())
    {
        std::cout << "Enter darkest secret: ";
        std::string darkestSecret;
        std::getline(std::cin, darkestSecret);
        this->contacts[i].setDarkestSecret(darkestSecret);
        if (std::cin.eof())
            return;
    }
}
