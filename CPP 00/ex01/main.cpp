#include <iostream>
#include <string>
#include <stdlib.h>
#include "phonebook.hpp"
#include "contact.hpp"

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
        phonebook.set_Contacts(i);
        i++;
    }
    bool restart = false;
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
        if (!std::cin)
            break;
        if (command == "ADD")
        {
            if (restart == true)
                phonebook.set_Contacts(i);
            phonebook.add_contact(i);
            i++;
            if (i == 8)
            {
                restart = true;
                i = 0;
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