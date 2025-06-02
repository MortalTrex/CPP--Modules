#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(std::string const & type);
		Cure();
		Cure &operator=(const Cure &other);
		~Cure();

		AMateria* clone() const;
};

#endif