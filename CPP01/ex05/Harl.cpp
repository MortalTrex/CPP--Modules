/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:23:19 by rbalazs           #+#    #+#             */
/*   Updated: 2025/05/03 20:23:20 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. " 
            << "I really do!" << std::endl;
}

void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put "
            << "enough bacon in my burger! If you did, I wouldn’t be asking for more!" 
            << std::endl;
}

void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. "
            << "I’ve been coming for years, whereas you started working here just last month." 
            << std::endl;
}

void Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    if (level.empty())
    {
        std::cerr << "Error: level is empty" << std::endl;
        return ;
    }
    std::string tab_level[4] = {"WARNING", "ERROR", "INFO", "DEBUG"};
    void		(Harl::*ptr_ft[4])(void) = { &Harl::warning, &Harl::error, &Harl::info, &Harl::debug };

    for (int i = 0 ; i < 4 ; i++)
    {
        if (tab_level[i] == level)
            (this->*ptr_ft[i])();
    }
}