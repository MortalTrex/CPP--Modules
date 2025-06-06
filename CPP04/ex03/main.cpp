#include "./inc/AMateria.hpp"
#include "./inc/Character.hpp"
#include "./inc/Cure.hpp"
#include "./inc/Ice.hpp"
#include "./inc/MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

	// AMateria* test = new Ice();
	// ICharacter* me = new Character("me");

	// AMateria* tmp;
	// tmp = src->createMateria("Ice");
	// me->equip(tmp);
	// tmp = src->createMateria("Cure");
	// me->equip(tmp);
	// ICharacter* bob = new Character("bob");
	// me->use(0, *bob);
	// me->use(1, *bob);
	// delete me;
	// delete bob;
	// delete test;

	// std::cout << "--------------------------------------" << std::endl;
	//MAIN_TESTEUR

	ICharacter*	character = new Character("character");
	ICharacter* character2 = new Character("character2");

	AMateria* a = src->createMateria("Ice");
	AMateria* b = src->createMateria("Ice");
	AMateria* c = src->createMateria("Ice");
	AMateria* d = src->createMateria("Ice");
	AMateria* e = src->createMateria("Cure");
	AMateria* f = src->createMateria("Cure");

	// test fully inventory
	character2->equip(a);
	character2->use(0, *character);
	character2->equip(b);
	character2->use(1, *character);
	character2->equip(c);
	character2->use(2, *character);
	character2->equip(d);
	character2->use(3, *character);

	character2->equip(e);
	character2->use(4, *character);

	// test equip and unequip
	std::cout << "ICI" << std::endl;
	character2->unequip(3);
	character2->unequip(1);
	character2->use(3, *character);
	character2->equip(f);
	character2->use(3, *character);

	delete character2;
	delete character;
	
	// test assignement Charactere (deep copy)
	Character louis("louis");
	Character vincent("vincent");

	louis.equip(src->createMateria("Ice"));
	vincent.equip(src->createMateria("Cure"));

	louis.use(0, vincent);
	vincent.use(0, louis);
	louis = vincent;

	louis.use(0, vincent);
	vincent.use(0, louis);

	louis.use(1, vincent); //<- Slot number 1 is empty

	std::cout << "--------------------------------------" << std::endl;

	// test instance AMateria
	
	// AMateria *no_instance = new AMateria();
	// ICharacter no_instance2;

	delete src;
	return 0;
}