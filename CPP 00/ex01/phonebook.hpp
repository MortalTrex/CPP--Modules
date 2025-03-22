#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "contact.hpp"
class Phonebook
{
	private:
		Contact contacts[8];

	public:
		Phonebook();
		~Phonebook();
		void add_contact(int i);
		void search_contact();
		void set_Contacts();
		void print_table();
};
#endif