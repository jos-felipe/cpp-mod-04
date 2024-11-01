#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
protected:
    std::string type; // O tipo do animal, protegido para acesso das classes derivadas

public:
    // Forma canônica ortodoxa
    Animal(); // Construtor padrão
    Animal(const Animal& other); // Construtor de cópia
    Animal& operator=(const Animal& other); // Operador de atribuição
    virtual ~Animal(); // Destrutor virtual para permitir polimorfismo correto

    // Métodos da classe
    virtual void makeSound() const; // Virtual para permitir override nas classes derivadas
    std::string getType() const; // Getter para o tipo
};

#endif
