# C++ Module 04 - Subtype polymorphism, abstract classes, interfaces

This project explores fundamental Object-Oriented Programming concepts in C++98, focusing on polymorphism, abstract classes, and interfaces. It consists of multiple exercises demonstrating different aspects of OOP.

## Key Concepts

- Subtype polymorphism
- Abstract classes
- Interfaces (through pure abstract classes)
- Deep vs. shallow copying
- Memory management
- Orthodox Canonical Form

## Project Structure

```
.
├── ex00/ (Polymorphism)
├── ex01/ (I don't want to set the world on fire)
├── ex02/ (Abstract class)
└── ex03/ (Interface & recap)
```

## Exercise Details

### Ex00: Polymorphism
- Base `Animal` class with derived `Dog` and `Cat` classes
- Virtual method implementation for `makeSound()`
- Demonstrates proper virtual destructor usage
- Includes wrong implementation example with `WrongAnimal` and `WrongCat`

### Ex01: Deep Copy & Memory Management
- Implementation of `Brain` class with 100 ideas
- Deep copy demonstration in `Dog` and `Cat` classes
- Proper memory allocation and deallocation
- Array management of `Animal` objects

### Ex02: Abstract Classes
- Modified `Animal` class to be abstract
- Prevents instantiation of base class
- Demonstrates pure virtual functions

### Ex03: Interfaces & RPG Game System
- Implementation of various interfaces (`ICharacter`, `IMateriaSource`)
- Concrete classes (`Character`, `MateriaSource`, `Ice`, `Cure`)
- Inventory management system
- Memory management for materias
- Deep copy implementation

## Implementation Details

### Key Features
- Memory leak prevention
- Proper inheritance hierarchies
- Virtual method implementations
- Deep copy mechanisms

### Memory Management
- All classes properly handle memory allocation
- No memory leaks in copy operations
- Proper cleanup in destructors
- Safe unequip operations

## Build Instructions

```bash
# Compile 
make

# Run tests and check for leaks
make leaks
```

## Design Notes

- Debug messages during object instation and destruction
- Orthodox Canonical Form compliance
- Color-coded console output for better readability

## Requirements

- C++98 standard
- Compilation with Wall -Wextra -Werror flags
- No memory leaks