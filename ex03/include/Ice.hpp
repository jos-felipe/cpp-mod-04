#ifndef	ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp" 
# include "ICharacter.hpp" 

class	Ice : public AMateria {

public:
	Ice();
	Ice(const Ice& src);
	Ice& operator=(const Ice& rhs);
	~Ice();

	AMateria*	clone() const;
	void	use(ICharacter& target);
};

#endif
