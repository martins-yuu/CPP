#include <iostream>

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

int main() {
  {
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << ": ";
    dog->makeSound();

    std::cout << cat->getType() << ": ";
    cat->makeSound();

    std::cout << meta->getType() << ": ";
    meta->makeSound();

    delete cat;
    delete dog;
    delete meta;
  }

  std::cout << "--------------------\n";

  {
    const WrongAnimal* cat = new WrongCat();

    std::cout << cat->getType() << ": ";
    cat->makeSound();

    delete cat;
  }
}
