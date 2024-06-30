#include "Dog.h"

#include <iostream>

#include "Animal.h"

Dog::Dog() : Animal() {
  std::cout << "(Dog) Default constructor called\n";

  m_type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other) {
  std::cout << "(Dog) Copy constructor called\n";
}

Dog::~Dog() { std::cout << "(Dog) Destructor called\n"; }

Dog& Dog::operator=(const Dog& other) {
  if (this != &other) {
    m_type = other.m_type;
  }

  return *this;
}

void Dog::makeSound() const { std::cout << "Bark\n"; }
