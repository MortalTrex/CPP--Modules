#include "./inc/AMateria.hpp"
#include "./inc/Character.hpp"
#include "./inc/Cure.hpp"
#include "./inc/Ice.hpp"
#include "./inc/MateriaSource.hpp"

int main()
{
	//MANDATORY

	std::cout << "\033[34mMandatory tests\033[0m" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("Ice");
	me->equip(tmp);
	tmp = src->createMateria("Cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete me;
	delete bob;

	std::cout << "--------------------------------------" << std::endl;

	//ADDITIONNAL TESTS

	std::cout << "\033[34mAdditional tests\033[0m" << std::endl;

	ICharacter* hero = new Character("hero");
	ICharacter*	enemy = new Character("enemy");

	AMateria* a = src->createMateria("Ice");
	AMateria* b = src->createMateria("Ice");
	AMateria* c = src->createMateria("Ice");
	AMateria* d = src->createMateria("Ice");
	AMateria* e = src->createMateria("Cure");
	AMateria* f = src->createMateria("Cure");

	// test fully inventory
	hero->equip(a);
	hero->use(0, *enemy);
	hero->equip(b);
	hero->use(1, *enemy);
	hero->equip(c);
	hero->use(2, *enemy);
	hero->equip(d);
	hero->use(3, *enemy);

	// test incorrect equip
	hero->equip(e);
	hero->use(4, *enemy);

	//test unequip
	hero->unequip(3);
	hero->unequip(1);
	hero->use(3, *enemy);
	hero->equip(f);
	hero->use(1, *enemy);

	delete hero;
	delete enemy;
	
	std::cout << "--------------------------------------" << std::endl;

	//test assignement Character (deep copy)

	std::cout << "\033[34mTests for Character\033[0m" << std::endl;

	Character hero1("hero1");
	Character hero2("hero2");

	hero1.equip(src->createMateria("Ice"));
	hero2.equip(src->createMateria("Cure"));
	hero2.equip(src->createMateria("Cure"));

	hero1.use(0, hero2);
	hero2.use(0, hero1);

	Character hero3(hero1);

	hero3.equip(src->createMateria("Ice"));
	hero3.use(0, hero2);
	hero3.unequip(0);

	std::cout << "\033[34mCopying hero1 to hero2\033[0m" << std::endl;
	hero1 = hero2;
	
	std::cout << "\033[34mHero 2 health hero 1\033[0m" << std::endl;
	hero2.use(0, hero1);
	
	std::cout << "\033[34mTests for hero1\033[0m" << std::endl;
	hero1.use(0, hero2);
	hero1.use(2, hero2);
	hero1.use(1, hero2);

	hero1.unequip(0);
	hero1.use(0, hero2);
	hero2.unequip(0);
	hero2.unequip(0);
	hero2.use(0, hero1);


	delete src;
	
	// test instance AMateria
	
	// AMateria *no_instance = new AMateria();
	// ICharacter no_instance2;

	return 0;
}