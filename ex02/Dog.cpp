#include "Dog.hpp"

Dog::Dog() : AAnimal() {
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
    for (int i = 0; i < 100; ++i)
        this->brain->ideas[i] = "I love chasing a ball!";
}

Dog::Dog(const Dog& other) : AAnimal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        AAnimal::operator=(other);
        for (int i = 0; i < 100; ++i)
            this->brain->ideas[i] = other.brain->ideas[i];
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

void Dog::makeSound() const {
    std::cout << this->type << ": Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
    return this->brain;
}
