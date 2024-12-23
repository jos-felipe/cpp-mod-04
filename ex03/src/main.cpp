#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int	main(void)
{
	{
		std::cout << BOLD << "*TEST 1. Subject*" << RESET << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		// Your Character must have a constructor taking its name as a parameter.
		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << std::endl << std::endl;
		std::cout << BOLD << "*TEST 2. MateriaSource Usage*" << RESET << std::endl;

		std::cout << YELLOW << "---Adding 5 materias shouln't fit---" << RESET << std::endl;
		IMateriaSource* src = new MateriaSource();
		for (int i = 0; i < 5; i++)
			src->learnMateria(new Ice());

		std::cout << YELLOW << "---Trying to create a materia that hasn't been learned---" << RESET << std::endl;
		AMateria* tmp;
		tmp = src->createMateria("cure");
		tmp = src->createMateria("type_x");
		std::cout << "createMateria return value: " << tmp << std::endl;

		delete src;
	}
	{
		std::cout << std::endl << std::endl;
		std::cout << BOLD << "*TEST 3. Inventory Deep Copy*" << RESET << std::endl;

		std::cout << YELLOW << "---Ed equips an ice---" << RESET << std::endl;
		Character* ed = new Character("edward");
		AMateria* tmp;
		tmp = new Ice();
		ed->equip(tmp);

		std::cout << YELLOW << "---Edd is created as a copy of Ed---" << RESET << std::endl;
		Character* edd = new Character(*ed);
		edd->use(0, *ed);

		std::cout << YELLOW << "---Ed is assigned to Eddy---" << RESET << std::endl;
		Character* eddy = new Character("eddy");
		*eddy = *ed;
		eddy->use(0, *ed);

		std::cout << YELLOW << "---Changind Ed inventory doen't change the others---" << RESET << std::endl;
		ed->unequip(0);
		edd->use(0, *eddy);
		eddy->use(0, *edd);

		std::cout << YELLOW << "---Copy deletes Alice's cure ability and replace it with Bob's ice---" << RESET << std::endl;
		Character* alice = new Character("Alice");
		AMateria* mat = new Cure();
		alice->equip(mat);
		Character* bob = new Character("Bob");
		AMateria* bob_mat = new Ice();
		bob->equip(bob_mat);
		alice->use(0, *bob);
		*alice = *bob;
		alice->use(0, *bob);

		std::cout << YELLOW << "---There are " << ed->getCharacterCount() << " players in the game---" << RESET << std::endl;

		delete ed;
		delete edd;
		delete eddy;
		delete alice;
		delete bob;
	}
	{
		std::cout << std::endl << std::endl;
		std::cout << BOLD << "*TEST 4. Character Habilities*" << RESET << std::endl;
		ICharacter* me = new Character("Pilgrim");

		std::cout << YELLOW << "---Unable to unequip empty inventory---" << RESET << std::endl;
		me->unequip(0);

		std::cout << YELLOW << "---Unable to unequip invalid slot---" << RESET << std::endl;
		me->unequip(5);

		std::cout << YELLOW << "---Unable to use invalid slot---" << RESET << std::endl;
		me->use(5, *me);

		std::cout << YELLOW << "---Unable to use an empty slot---" << RESET << std::endl;
		me->use(1, *me);

		std::cout << YELLOW << "---Unequip should not delete materia---" << RESET << std::endl;
		AMateria* mat;
		mat = new Ice();
		me->equip(mat);
		me->unequip(0);
		std::cout << "Materia that was unequipped is of type: " << mat->getType() << std::endl;
		
		std::cout << YELLOW << "---Adding 5 materias shouln't fit---" << RESET << std::endl;
		for (int i = 0; i < 5; i++)
		{
			AMateria* tmp;
			tmp = new Cure();
			me->equip(tmp);
		}

		delete me;
	}
	return 0;
}
