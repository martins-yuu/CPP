#include "Dog.h"

#include <iostream>

#include "Animal.h"
#include "Brain.h"

Dog::Dog() : Animal() {
  std::cout << "(Dog) Default constructor called\n";

  m_type = "Dog";
  m_brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other), m_brain(new Brain(*other.m_brain)) {
  std::cout << "(Dog) Copy constructor called\n";
}

Dog::~Dog() {
  std::cout << "(Dog) Destructor called\n";

  delete m_brain;
}

Dog& Dog::operator=(const Dog& other) {
  if (this != &other) {
    delete m_brain;

    m_type = other.m_type;
    m_brain = new Brain(*other.m_brain);
  }

  return *this;
}

void Dog::makeSound() const { std::cout << "Bark\n"; }
