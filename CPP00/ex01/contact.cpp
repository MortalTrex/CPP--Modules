/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 19:41:00 by rbalazs           #+#    #+#             */
/*   Updated: 2025/03/23 19:41:01 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <iostream>
#include <string>

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::setIndex(int index)
{
    this->_index = index;
}

void Contact::setFirstName(std::string first_name)
{
    this->_first_name = first_name;
}

void Contact::setLastName(std::string last_name)
{
    this->_last_name = last_name;
}

void Contact::setNickname(std::string nickname)
{
    this->_nickname = nickname;
}

void Contact::setPhoneNumber(std::string phone_number)
{
    this->_phone_number = phone_number;
}

void Contact::setDarkestSecret(std::string darkest_secret)
{
    this->_darkest_secret = darkest_secret;
}

std::string Contact::getFirstName()
{
    return this->_first_name;
}

std::string Contact::getLastName()
{
    return this->_last_name;
}

std::string Contact::getNickname()
{
    return this->_nickname;
}

std::string Contact::getPhoneNumber()
{
    return this->_phone_number;
}

std::string Contact::getDarkestSecret()
{
    return this->_darkest_secret;
}

int Contact::getIndex()
{
    return this->_index;
}