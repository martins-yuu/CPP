#include "ClapTrap.h"

int main() {
  ClapTrap clapTrap("CT-42");

  clapTrap.takeDamage(7);
  clapTrap.beRepaired(2);
  clapTrap.attack("Bandit");
}
