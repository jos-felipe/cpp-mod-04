#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(AMateria const & other) : _type(other._type) {}

AMateria & AMateria::operator=(AMateria const & other) {
	(void)other;
	return *this;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter & target) {
	std::cout << "A generic Materia is trying to be used on " << target.getName() << std::endl;
}
