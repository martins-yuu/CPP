#include "Animal.h"

#include <iostream>

Animal::Animal() : m_type("Animal") {
  std::cout << "(Animal) Default constructor called\n";
}

Animal::Animal(const Animal &other) : m_type(other.m_type) {
  std::cout << "(Animal) Copy constructor called\n";
}

Animal &Animal::operator=(const Animal &other) {
  if (this != &other) {
    m_type = other.m_type;
  }

  return *this;
}

Animal::~Animal() { std::cout << "(Animal) Destructor called\n"; }

const std::string &Animal::getType() const { return m_type; }

void Animal::makeSound() const { std::cout << "???\n"; }
