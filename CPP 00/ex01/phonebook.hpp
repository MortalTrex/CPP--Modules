#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "contact.hpp"
class Phonebook
{
	private:
		Contact _contacts[8];

	public:
		Phonebook();
		~Phonebook();
		void add_contact(int i);
		void search_contact();
		void set_Contacts(int i);
		void print_table();
};
#endif