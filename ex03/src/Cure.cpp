#include "Cure.hpp" 

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure& src) : AMateria(src)
{
}

Cure&	Cure::operator=(const Cure& rhs)
{
	(void)rhs;
	return *this;
}

Cure::~Cure()
{
}

AMateria*	Cure::clone() const
{
	return new Cure(*this);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
