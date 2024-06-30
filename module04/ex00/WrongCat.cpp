#include "WrongCat.h"

#include <iostream>

#include "WrongAnimal.h"

WrongCat::WrongCat() : WrongAnimal() {
  std::cout << "(WrongCat) Default constructor called\n";

  m_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
  std::cout << "(WrongCat) Copy constructor called\n";
}

WrongCat::~WrongCat() { std::cout << "(WrongCat) Destructor called\n"; }

WrongCat& WrongCat::operator=(const WrongCat& other) {
  if (this != &other) {
    m_type = other.m_type;
  }

  return *this;
}

void WrongCat::makeSound() const { std::cout << "Meow\n"; }
