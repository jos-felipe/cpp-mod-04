#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include "IMateriaSource.hpp"
# define MEMORY_SIZE 4

class	MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource& rhs);
	MateriaSource& operator=(const MateriaSource& rhs);
	~MateriaSource();

	void	learnMateria(AMateria* m);
	AMateria*	createMateria(std::string const& type);

private:
	AMateria*	_memory[MEMORY_SIZE];
};

#endif
