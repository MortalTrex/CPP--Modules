/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:23:51 by rbalazs           #+#    #+#             */
/*   Updated: 2025/05/03 20:23:52 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error : Bad arguments" << std::endl;
		return (EXIT_FAILURE);
	}
	ft_replace(argv[1], argv[2], argv[3]);
	return (EXIT_SUCCESS);
}