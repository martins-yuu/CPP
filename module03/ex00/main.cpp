#include "ClapTrap.h"

int main() {
  ClapTrap clapTrap("ClapTrap");

  clapTrap.takeDamage(7);
  clapTrap.beRepaired(2);
  clapTrap.attack("Bandit");
}
