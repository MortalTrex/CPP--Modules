#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
		Ice(std::string const & type);
		Ice();
		Ice &operator=(const Ice &other);
		~Ice();

		Ice* clone() const;
		void use(ICharacter& target);
};

#endif