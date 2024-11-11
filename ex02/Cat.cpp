#include "Cat.hpp"

Cat::Cat() : AAnimal() {
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
    for (int i = 0; i < 100; ++i)
        this->brain->ideas[i] = "I love lasagna!";
}

Cat::Cat(const Cat& other) : AAnimal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        AAnimal::operator=(other);
        for (int i = 0; i < 100; ++i)
            this->brain->ideas[i] = other.brain->ideas[i];
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

void Cat::makeSound() const {
    std::cout << this->type << ": Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
    return this->brain;
}
