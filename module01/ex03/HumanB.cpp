#include <cstddef>
#include <iostream>

#include "HumanB.h"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

void HumanB::setWeapon(Weapon &weapon) { _weapon = &weapon; }

void HumanB::attack() {
  if (!this->_weapon) {
    std::cout << this->_name << " attacks with their bare hands" << '\n';
    return;
  }

  std::cout << _name << " attacks with their " << _weapon->getType() << '\n';
}
