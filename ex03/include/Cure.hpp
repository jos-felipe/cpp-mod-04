#ifndef	CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp" 
# include "ICharacter.hpp" 

class	Cure : public AMateria {

public:
	Cure();
	Cure(const Cure& src);
	Cure& operator=(const Cure& rhs);
	~Cure();

	AMateria*	clone() const;
	void	use(ICharacter& target);
};

#endif
