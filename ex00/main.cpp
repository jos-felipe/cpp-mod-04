#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

void testCorrectPolymorphism() {
    std::cout << "\n=== Testing Correct Polymorphism ===" << std::endl;
    
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "\nTypes:" << std::endl;
    std::cout << "Animal type: " << animal->getType() << std::endl;
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;
    
    std::cout << "\nSounds:" << std::endl;
    std::cout << "Animal sound: ";
    animal->makeSound();
    std::cout << "Dog sound: ";
    dog->makeSound();
    std::cout << "Cat sound: ";
    cat->makeSound();

    delete animal;
    delete dog;
    delete cat;
}

void testWrongPolymorphism() {
    std::cout << "\n=== Testing Wrong Polymorphism ===" << std::endl;
    
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();  // Points to WrongCat but treated as WrongAnimal
    const WrongCat* actualWrongCat = new WrongCat();  // Direct WrongCat pointer

    std::cout << "\nTypes:" << std::endl;
    std::cout << "WrongAnimal type: " << wrongAnimal->getType() << std::endl;
    std::cout << "WrongCat through WrongAnimal type: " << wrongCat->getType() << std::endl;
    std::cout << "WrongCat direct type: " << actualWrongCat->getType() << std::endl;
    
    std::cout << "\nSounds:" << std::endl;
    std::cout << "WrongAnimal sound: ";
    wrongAnimal->makeSound();
    std::cout << "WrongCat through WrongAnimal sound (will be wrong): ";
    wrongCat->makeSound();  // Will use WrongAnimal's makeSound due to non-virtual function
    std::cout << "WrongCat direct sound: ";
    actualWrongCat->makeSound();  // Will use WrongCat's makeSound

    delete wrongAnimal;
    delete wrongCat;
    delete actualWrongCat;
}

void testCopyConstructors() {
    std::cout << "\n=== Testing Copy Constructors ===" << std::endl;
    
    // Test regular animals
    Cat originalCat;
    Cat copiedCat(originalCat);
    
    // Test wrong animals
    WrongCat originalWrongCat;
    WrongCat copiedWrongCat(originalWrongCat);
    
    std::cout << "\nTesting copied sounds:" << std::endl;
    std::cout << "Original Cat: ";
    originalCat.makeSound();
    std::cout << "Copied Cat: ";
    copiedCat.makeSound();
    std::cout << "Original WrongCat: ";
    originalWrongCat.makeSound();
    std::cout << "Copied WrongCat: ";
    copiedWrongCat.makeSound();
}

int main() {
    std::cout << "Starting Polymorphism Tests\n" << std::endl;

    testCorrectPolymorphism();
    testWrongPolymorphism();
    testCopyConstructors();

    std::cout << "\nAll tests completed.\n" << std::endl;
    return 0;
}
