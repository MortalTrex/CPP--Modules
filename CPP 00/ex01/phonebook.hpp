#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "contact.hpp"
class Phonebook
{
	public:
		Contact contacts[8];
		void add_contact(int i);
		void search_contact();
};

#endif