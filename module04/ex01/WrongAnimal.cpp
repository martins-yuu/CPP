#include "WrongAnimal.h"

#include <iostream>

WrongAnimal::WrongAnimal() {
  std::cout << "(WrongAnimal) Default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : m_type(other.m_type) {
  std::cout << "(WrongAnimal) Copy constructor called\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
  if (this != &other) {
    m_type = other.m_type;
  }

  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "(WrongAnimal) Destructor called\n";
}

const std::string &WrongAnimal::getType() const { return m_type; }

void WrongAnimal::makeSound() const { std::cout << "???\n"; }
