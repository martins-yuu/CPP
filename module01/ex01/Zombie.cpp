#include "Zombie.h"

#include <iostream>

Zombie::Zombie() {}

Zombie::~Zombie() { std::cout << "Destructing " << _name << '\n'; }

void Zombie::announce() {
  std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << '\n';
}
