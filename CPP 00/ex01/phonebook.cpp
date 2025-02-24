#include <iostream>
#include <string>
#include <stdlib.h>
#include "phonebook.hpp"
#include "contact.hpp"


static void print_info(std::string info)
{
	if (info.length() > 10)
			std::cout << info.substr(0, 9) << ".";
		else
			std::cout << info;
}

void Phonebook::search_contact()
{
	int i = 0;
	std::string search_index;

	std::cout << "Enter the index of the contact [1 to 8]: ";
	std::getline(std::cin, search_index);

	while (i < 8)
	{
		if (contacts[i].index == atoi(search_index.c_str()))
		{
			std::cout << "\033[1;34m---------------------------------------------\033[0m" << std::endl
						<< "|  INDEX | FIRST NAME | LAST NAME | NICKNAME     |" << std::endl
					  << "\033[1;32m|     \033[0m" << contacts[i].index
					  << "\033[1;32m| \033[0m"; print_info(contacts[i].first_name);
					  std::cout << "\033[1;32m|  \033[0m"; print_info(contacts[i].last_name);
					  std::cout << "\033[1;32m| \033[0m"; print_info(contacts[i].nickname); std::cout << "   |" << std::endl;
					  std::cout << "\033[1;34m---------------------------------------------\033[0m" << std::endl;
		}
		i++;
	}
}

void Phonebook::add_contact(int i)
{
	std::cout << "Enter first name: ";
	std::getline(std::cin, this->contacts[i].first_name);

	std::cout << "Enter last name: ";
	std::getline(std::cin, this->contacts[i].last_name);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, this->contacts[i].nickname);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, this->contacts[i].phone_number);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, this->contacts[i].darkest_secret);
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
		phonebook.contacts[i].index = i + 1;
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
	}
	return 0;
}
