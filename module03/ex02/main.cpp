#include "FragTrap.h"

int main() {
  FragTrap fragTrap("FT-42");

  fragTrap.takeDamage(7);
  fragTrap.beRepaired(2);
  fragTrap.attack("Bandit");
  fragTrap.highFivesGuy();
}
