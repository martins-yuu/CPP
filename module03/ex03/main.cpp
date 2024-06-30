#include "DiamondTrap.h"

int main() {
  DiamondTrap diamondTrap("DT-42");

  diamondTrap.takeDamage(7);
  diamondTrap.beRepaired(2);
  diamondTrap.attack("Bandit");
  diamondTrap.whoAmI();
}
