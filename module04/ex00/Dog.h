#pragma once

#include "Animal.h"

class Dog : public Animal {
 public:
  Dog();
  Dog(const Dog& other);
  Dog& operator=(const Dog& other);
  virtual ~Dog();

  virtual void makeSound() const;
};
