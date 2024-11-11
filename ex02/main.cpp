#include "Dog.hpp"
#include "Cat.hpp"
#include "Colors.hpp"

#define ARRAY_SIZE 4

void testAbstractClass() {
    std::cout << BOLDYELLOW << "\n=== Testing Abstract Class ===" << RESET << std::endl;
    
    // This would not compile:
    // AAnimal abstract = AAnimal();
    // AAnimal* abstract = new AAnimal();
    
    std::cout << BLUE << "Creating animals using base class pointers:" << RESET << std::endl;
    const AAnimal* dog = new Dog();
    const AAnimal* cat = new Cat();
    
    std::cout << "\n" << BLUE << "Testing makeSound() through base class pointer:" << RESET << std::endl;
    dog->makeSound();
    cat->makeSound();
    
    std::cout << "\n" << BLUE << "Cleaning up:" << RESET << std::endl;
    delete dog;
    delete cat;
}

void dogDeepCopy() {
    std::cout << BOLDGREEN << "\n=== Dog Deep Copy ===" << RESET << std::endl;
    
    Dog* originalDog = new Dog();
    
    std::cout << YELLOW << "\nCreating copy of Dog using copy constructor..." << RESET << std::endl;
    Dog* copyDog = new Dog(*originalDog);
    
    std::cout << CYAN << "\nOriginal dog idea: " << originalDog->getBrain()->ideas[0] << RESET << std::endl;
    std::cout << CYAN << "Copy dog idea: " << copyDog->getBrain()->ideas[0] << RESET << std::endl;
    
    std::cout << YELLOW << "\nModifying copy dog's idea..." << RESET << std::endl;
    copyDog->getBrain()->ideas[0] = "I want to pee.";
    
    std::cout << CYAN << "Original dog idea: " << originalDog->getBrain()->ideas[0] << RESET << std::endl;
    std::cout << CYAN << "Copy dog idea: " << copyDog->getBrain()->ideas[0] << RESET << std::endl;
    
    delete originalDog;
    delete copyDog;
}

void catDeepCopy() {
    std::cout << BOLDGREEN << "\n=== Cat Deep Copy ===" << RESET << std::endl;
    
    Cat* originalCat = new Cat();
    
    std::cout << YELLOW << "\nCreating copy of Cat using copy constructor..." << RESET << std::endl;
    Cat* copyCat = new Cat(*originalCat);
    
    std::cout << CYAN << "\nOriginal Cat idea: " << originalCat->getBrain()->ideas[0] << RESET << std::endl;
    std::cout << CYAN << "Copy Cat idea: " << copyCat->getBrain()->ideas[0] << RESET << std::endl;
    
    std::cout << YELLOW << "\nModifying copy Cat's idea..." << RESET << std::endl;
    copyCat->getBrain()->ideas[0] = "I want to pee.";
    
    std::cout << CYAN << "Original Cat idea: " << originalCat->getBrain()->ideas[0] << RESET << std::endl;
    std::cout << CYAN << "Copy Cat idea: " << copyCat->getBrain()->ideas[0] << RESET << std::endl;
    
    delete originalCat;
    delete copyCat;
}

int main(void)
{
    testAbstractClass();
	dogDeepCopy();
    catDeepCopy();

    std::cout << BOLDGREEN << "\n=== Creating array of animals ===" << RESET << std::endl;
    
    const AAnimal* animals[ARRAY_SIZE];
    
    for (int i = 0; i < ARRAY_SIZE / 2; i++) {
        std::cout << BLUE << "\nCreating Dog " << i << RESET << std::endl;
        animals[i] = new Dog();
    }
    
    for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; i++) {
        std::cout << MAGENTA << "\nCreating Cat " << i << RESET << std::endl;
        animals[i] = new Cat();
    }
    
    std::cout << BOLDYELLOW << "\n=== Making all animals sound ===" << RESET << std::endl;
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << "Animal " << i << " makes: ";
        animals[i]->makeSound();
    }
    
    std::cout << BOLDRED << "\n=== Deleting all animals ===" << RESET << std::endl;
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << "\nDeleting animal " << i << std::endl;
        delete animals[i];
    }
    
    return 0;
}