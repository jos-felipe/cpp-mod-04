#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(const AMateria& src) : _type(src._type)
{
}

AMateria&	AMateria::operator=(const AMateria& rhs)
{
	(void)rhs;
	return *this;
}

AMateria::~AMateria()
{
}

AMateria::AMateria(std::string const& type) : _type(type)
{
}

std::string const&	AMateria::getType() const
{
	return this->_type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "A generic Materia is trying to be used on " << target.getName() << std::endl;
}
