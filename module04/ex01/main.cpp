#include <cstddef>

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

int main() {
  static const std::size_t animalCount = 42;
  Animal *animals[animalCount];

  for (std::size_t i = 0; i < animalCount; ++i) {
    if (i % 2 == 0) {
      animals[i] = new Dog();
    } else {
      animals[i] = new Cat();
    }
  }

  for (std::size_t i = 0; i < animalCount; ++i) {
    animals[i]->makeSound();
  }

  for (std::size_t i = 0; i < animalCount; ++i) {
    delete animals[i];
  }
}
