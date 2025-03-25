/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 19:41:13 by rbalazs           #+#    #+#             */
/*   Updated: 2025/03/23 19:41:14 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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