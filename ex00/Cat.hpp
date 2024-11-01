// Cat.hpp
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
    // Forma canônica ortodoxa
    Cat();                              // Construtor padrão
    Cat(const Cat& other);              // Construtor de cópia
    Cat& operator=(const Cat& other);   // Operador de atribuição
    virtual ~Cat();                     // Destrutor

    // Override da função makeSound
    virtual void makeSound() const;
};

#endif
