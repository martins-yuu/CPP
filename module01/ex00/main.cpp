#include "Zombie.h"

int main() {
  // Test heap-allocated Zombie
  Zombie *zombie = newZombie("Bob");

  {
    Zombie *zombie = newZombie("Dave");

    zombie->announce();

    delete zombie;
  }

  zombie->announce();

  // Test stack-allocated Zombie
  randomChump("Carl");

  delete zombie;
}
