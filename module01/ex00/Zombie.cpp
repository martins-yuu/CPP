#include "Zombie.h"

#include <iostream>

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie() { std::cout << _name << '\n'; }

void Zombie::announce() {
  std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << '\n';
}
