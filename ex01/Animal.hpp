#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {

public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

    // Métodos da classe
    virtual void makeSound() const; 
    std::string getType() const;

protected:
    std::string type;
};

#endif
