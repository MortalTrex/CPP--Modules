#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"

class Cure : public AMateria
{
	public:
		Cure(std::string const & type);
		Cure();
		Cure &operator=(const Cure &other);
		virtual ~Cure();

		Cure* clone() const;
		void use(ICharacter& target);
};

#endif