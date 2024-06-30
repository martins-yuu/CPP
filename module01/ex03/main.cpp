#include <iostream>

#include "HumanA.h"
#include "HumanB.h"
#include "Weapon.h"

#define MAGENTA "\033[35m"
#define RESET "\033[0m"

int main() {
  {
    Weapon weapon = Weapon(MAGENTA "crude spiked club" RESET);
    HumanA human("Bob", weapon);

    human.attack();

    weapon.setType(MAGENTA "some other type of club" RESET);
    human.attack();
  }

  std::cout << '\n';

  {
    Weapon weapon = Weapon(MAGENTA "crude spiked club" RESET);
    HumanB human("Jim");

    human.attack();

    human.setWeapon(weapon);
    human.attack();

    weapon.setType(MAGENTA "some other type of club" RESET);
    human.attack();
  }
}
