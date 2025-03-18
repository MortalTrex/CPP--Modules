#include <iostream>
#include <string>
#include <stdlib.h>
#include "phonebook.hpp"
#include "contact.hpp"

static bool verif_phonenumber(std::string str)
{
    if (str > "9" || str < "0")
    {
        std::cout << "\033[1;31mPhone number must be numbers\033[0m" << std::endl;
        return false;
    }
    return true;
}

static void print_info(std::string info)
{
    if (info.length() > 10)
        std::cout << "| " << info.substr(0, 9) << "." << " |";
    else
        std::cout << "| " << info << " |";
}


Phonebook::Phonebook()		
{
}

Phonebook::~Phonebook()
{
}

void Phonebook::search_contact()
{
    int i = 0;
    std::string search_index;

    std::cout << "\033[1;34mEnter the index of the contact [1 to 8]: \033[0m";
    std::getline(std::cin, search_index);

    while (i < 8)
    {
        if (contacts[i].getIndex() == atoi(search_index.c_str()))
        {
            std::cout << "\033[1;33m+--------+------------+------------+------------+\033[0m" << std::endl;
            std::cout << "\033[1;33m|  INDEX | FIRST NAME | LAST NAME  | NICKNAME   |\033[0m" << std::endl;
            std::cout << "\033[1;33m+--------+------------+------------+------------+\033[0m" << std::endl;

            std::cout << "|   " << contacts[i].getIndex() << "    | ";
            print_info(contacts[i].getFirstName());
            print_info(contacts[i].getLastName());
            print_info(contacts[i].getNickname());
            std::cout << std::endl;

            std::cout << "\033[1;33m+--------+------------+------------+------------+\033[0m" << std::endl;
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

int main(int argc, char **argv)
{
    (void)argv;
    if (argc != 1)
        return 0;
    Phonebook phonebook;
    std::string command;

    int i = 0;
    while (i < 8)
    {
        phonebook.contacts[i].setIndex(i + 1);
        phonebook.contacts[i].setFirstName("");
        phonebook.contacts[i].setLastName("");
        phonebook.contacts[i].setNickname("");
        phonebook.contacts[i].setPhoneNumber("");
        phonebook.contacts[i].setDarkestSecret("");
        i++;
    }
    i = 0;
    std::cout << "\033[1;36m*********************************************\033[0m" << std::endl;
    std::cout << "\033[1;36m*                                           *\033[0m" << std::endl;
    std::cout << "\033[1;36m*               PHONEBOOK                   *\033[0m" << std::endl;
    std::cout << "\033[1;36m*                                           *\033[0m" << std::endl;
    std::cout << "\033[1;36m*********************************************\033[0m" << std::endl;
    while (1)
    {
        std::cout << "\033[1;36mEnter your command [ADD | SEARCH | EXIT]: \033[0m";
        std::getline(std::cin, command);
        if (std::cin.eof())
            break;
        if (command == "ADD")
        {
            phonebook.add_contact(i);
            i++;
            if (i == 8)
                i = 0;
        }
        else if (command == "SEARCH")
            phonebook.search_contact();
        else if (command == "EXIT")
            break;
        else
            std::cout << "\033[1;31mInvalid command\033[0m" << std::endl;
    }
    return 0;
}
