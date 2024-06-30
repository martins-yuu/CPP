#include "Cat.h"

#include <iostream>

#include "Animal.h"
#include "Brain.h"

Cat::Cat() : Animal() {
  std::cout << "(Cat) Default constructor called\n";

  m_type = "Cat";
  m_brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other), m_brain(new Brain(*other.m_brain)) {
  std::cout << "(Cat) Copy constructor called\n";
}

Cat::~Cat() {
  std::cout << "(Cat) Destructor called\n";

  delete m_brain;
}

Cat& Cat::operator=(const Cat& other) {
  if (this != &other) {
    delete m_brain;

    m_type = other.m_type;
    m_brain = new Brain(*other.m_brain);
  }

  return *this;
}

void Cat::makeSound() const { std::cout << "Meow\n"; }
