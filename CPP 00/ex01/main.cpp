#include <iostream>
#include <string>
#include <stdlib.h>
#include "phonebook.hpp"
#include "contact.hpp"

int main(int argc, char **argv)
{
    (void)argv;
    if (argc != 1)
    {
        std::cout << "\033[1;31mInvalid number of arguments\033[0m" << std::endl;
        return 1;
    }
    Phonebook phonebook;
    std::string command;

    bool restart = false;
    int nbContact = 0;
    std::cout << "\033[1;36m*********************************************\n"
              << "*                                           *\n"
              << "*               PHONEBOOK                   *\n"
              << "*                                           *\n"
              << "*********************************************\033[0m" << std::endl;
    while (true)
    {
        std::cout << "\033[1;36mEnter your command [ADD | SEARCH | EXIT]: \033[0m";
        std::getline(std::cin, command);
        if (!std::cin)
            break;
        if (command == "ADD")
        {
            if (restart)
                phonebook.set_Contacts(nbContact);
            phonebook.add_contact(nbContact);
            nbContact++;
            if (nbContact == 8)
            {
                restart = true;
                nbContact = 0;
            }
        }
        else if (command == "SEARCH")
        {
            phonebook.print_table();
            phonebook.search_contact();
        }
        else if (command == "EXIT")
            break;
        else
            std::cout << "\033[1;31mInvalid command\033[0m" << std::endl;
    }
    return 0;
}