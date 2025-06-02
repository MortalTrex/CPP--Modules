#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(std::string const & type);
		Ice();
		Ice &operator=(const Ice &other);
		~Ice();

		AMateria* clone() const;
};

#endif