#include "AMateria.hpp"

// Constructor
AMateria::AMateria(std::string const & type) : _type(type) {}

// Copy Constructor
AMateria::AMateria(AMateria const & other) : _type(other._type) {}

// Destructor
AMateria::~AMateria() {}

// Assignment Operator
AMateria & AMateria::operator=(AMateria const & other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

// Get the type of the materia
std::string const & AMateria::getType() const {
	return this->_type;
}

// Use the materia
void AMateria::use(ICharacter & target) {
	// Implementation of use function
	// This should be overridden in derived classes
}