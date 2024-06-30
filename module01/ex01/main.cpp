#include <iostream>

#include "Zombie.h"

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

int main() {
  static const int zombieCount = 42;

  Zombie *zombies = zombieHorde(zombieCount, "Alberto");

  for (int i = 0; i < zombieCount; ++i) {
    std::cout << GREEN "Zombie " RESET << i << " " CYAN "says:" RESET << '\n';

    std::cout << YELLOW;
    zombies[i].announce();
    std::cout << RESET << '\n';
  }

  delete[] zombies;
}
