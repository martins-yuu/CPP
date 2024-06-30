#pragma once

#include <string>

#include "Weapon.h"

class HumanA {
public:
  HumanA(std::string name, Weapon &weapon);

  void attack();

private:
  std::string _name;
  Weapon &_weapon;
};
