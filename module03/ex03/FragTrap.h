#pragma once

#include "ClapTrap.h"

class FragTrap : public virtual ClapTrap {
public:
  FragTrap();
  FragTrap(const std::string &name);
  FragTrap(const FragTrap &other);
  FragTrap &operator=(const FragTrap &other);
  ~FragTrap();

  void attack(const std::string &target);
  void highFivesGuy();
};
