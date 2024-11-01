#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
    // Forma canônica ortodoxa
    Dog();                              // Construtor padrão
    Dog(const Dog& other);              // Construtor de cópia
    Dog& operator=(const Dog& other);   // Operador de atribuição
    virtual ~Dog();                     // Destrutor

    // Override da função makeSound
    virtual void makeSound() const;
};

#endif
