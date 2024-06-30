#include "Cat.h"

#include <iostream>

#include "Animal.h"

Cat::Cat() : Animal() {
  std::cout << "(Cat) Default constructor called\n";

  m_type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other) {
  std::cout << "(Cat) Copy constructor called\n";
}

Cat::~Cat() { std::cout << "(Cat) Destructor called\n"; }

Cat& Cat::operator=(const Cat& other) {
  if (this != &other) {
    m_type = other.m_type;
  }

  return *this;
}

void Cat::makeSound() const { std::cout << "Meow\n"; }
