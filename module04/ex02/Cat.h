#pragma once

#include "Animal.h"
#include "Brain.h"

class Cat : public Animal {
 public:
  Cat();
  Cat(const Cat& other);
  Cat& operator=(const Cat& other);
  virtual ~Cat();

  virtual void makeSound() const;

 private:
  Brain* m_brain;
};
