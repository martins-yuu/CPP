#pragma once

#include "FragTrap.h"
#include "ScavTrap.h"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
  DiamondTrap();
  DiamondTrap(const std::string &name);
  DiamondTrap(const DiamondTrap &other);
  DiamondTrap &operator=(const DiamondTrap &other);
  ~DiamondTrap();

  void attack(const std::string &target);
  void whoAmI();

private:
  std::string _name;
};
