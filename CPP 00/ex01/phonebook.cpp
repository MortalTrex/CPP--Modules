#include <iostream>
#include <string>
#include "phonebook.hpp"
#include "contact.hpp"

void Phonebook::search_contact()
{
	int i = 0;
	while (i < 8)
	{
			std::cout << "\033[1;34m---------------------------------------------\033[0m" << std::endl
					  << "\033[1;32mIndex : \033[0m" << contacts[i].index << std::endl
					  << "\033[1;32mFirst Name : \033[0m" << contacts[i].first_name << std::endl
					  << "\033[1;32mLast Name :  \033[0m" << contacts[i].last_name << std::endl
					  << "\033[1;32mNickname : \033[0m" << contacts[i].nickname << std::endl
					  << "\033[1;32mPhone Number : \033[0m" << contacts[i].phone_number << std::endl
					  << "\033[1;32mDarkest Secret : \033[0m" << contacts[i].darkest_secret << std::endl
					  << "\033[1;34m---------------------------------------------\033[0m" << std::endl;
		i++;
	}
}

void Phonebook::add_contact()
{
	std::cout << "Enter first name : ";
	std::getline(std::cin, contacts->first_name);

	std::cout << "Enter last name : ";
	std::getline(std::cin, contacts->last_name);

	std::cout << "Enter nickname : ";
	std::getline(std::cin, contacts->nickname);

	std::cout << "Enter phone number : ";
	std::getline(std::cin, contacts->phone_number);

	std::cout << "Enter darkest secret : ";
	std::getline(std::cin, contacts->darkest_secret);
}

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
		return 0;
	Phonebook phonebook;
	std::string command;

	int i = 0;
	int index = 0;
	while (i < 8)
	{
		phonebook.contacts[i].index = i;
		i++;
	}
	while(1)
	{
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			phonebook.contacts[index].add_contact();
			index++;
		}
		else if (command == "SEARCH")
			phonebook.search_contact();
		else if (command == "EXIT")
			break;
	}
	return 0;
}
