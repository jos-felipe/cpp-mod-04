#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

void testBasicFunctionality() {
    std::cout << "\n=== Basic Functionality Tests ===" << std::endl;
    
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "\nTesting getType():" << std::endl;
    std::cout << "j Type: " << j->getType() << std::endl;
    std::cout << "i Type: " << i->getType() << std::endl;
    
    std::cout << "\nTesting makeSound():" << std::endl;
    std::cout << "i (Cat) sound: ";
    i->makeSound();
    std::cout << "j (Dog) sound: ";
    j->makeSound();
    std::cout << "meta (Animal) sound: ";
    meta->makeSound();

    // Cleanup
    delete meta;
    delete j;
    delete i;
}

void testCopyConstructors() {
    std::cout << "\n=== Copy Constructor Tests ===" << std::endl;
    
    std::cout << "\nTesting Dog copy:" << std::endl;
    Dog originalDog;
    Dog copiedDog(originalDog);
    
    std::cout << "\nTesting Cat copy:" << std::endl;
    Cat originalCat;
    Cat copiedCat(originalCat);
    
    std::cout << "\nTesting sounds of copied animals:" << std::endl;
    std::cout << "Original Dog: ";
    originalDog.makeSound();
    std::cout << "Copied Dog: ";
    copiedDog.makeSound();
    std::cout << "Original Cat: ";
    originalCat.makeSound();
    std::cout << "Copied Cat: ";
    copiedCat.makeSound();
}

void testAssignmentOperators() {
    std::cout << "\n=== Assignment Operator Tests ===" << std::endl;
    
    Dog dog1;
    Dog dog2;
    std::cout << "\nTesting Dog assignment:" << std::endl;
    dog2 = dog1;
    
    Cat cat1;
    Cat cat2;
    std::cout << "\nTesting Cat assignment:" << std::endl;
    cat2 = cat1;
}

int main() {
    std::cout << "Starting Animal Class Tests\n" << std::endl;

    testBasicFunctionality();
    testCopyConstructors();
    testAssignmentOperators();

    std::cout << "\nAll tests completed.\n" << std::endl;
    return 0;
}