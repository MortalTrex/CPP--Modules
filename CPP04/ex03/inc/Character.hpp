#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <vector>
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria* _inventory[4];
		std::vector<AMateria*> _trashinventory;
		
	public:
		Character();
		Character(std::string const &name);
		Character &operator=(const Character &other);
		virtual ~Character();
		
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif