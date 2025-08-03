/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   F.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:10:56 by mgalvez           #+#    #+#             */
/*   Updated: 2025/07/31 21:25:11 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <cmath>

int	F(int n)
{
	int	sum = 0;
	int	k = 1;
		
	while (k <= n)
	{
		double	value = (3.0 / 4.0) * k;
		sum += static_cast<int>(ceil(log2(value)));
		++k;
	}
	return (sum);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error, wrong number of arguments" << std::endl;
		return (1);
	}

	int	len = atoi(argv[1]);
	if (len < 1)
	{
		std::cerr << "Error, arg needs to be a positive number" << std::endl;
		return (1);
	}

	std::cout << "Max number of comparison: " << F(len) << std::endl;
	return (0);
}
