#include "ScavTrap.h"

int main() {
  ScavTrap scavTrap("ST-42");

  scavTrap.takeDamage(7);
  scavTrap.beRepaired(2);
  scavTrap.attack("Bandit");
  scavTrap.guardGate();
}
