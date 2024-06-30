#include <iostream>

#include "ScavTrap.h"

ScavTrap::ScavTrap() : ClapTrap() {
  std::cout << "(ScavTrap) Default constructor called\n";

  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
  std::cout << "(ScavTrap) Name constructor called\n";

  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
  std::cout << "(ScavTrap) Copy constructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  std::cout << "(ScavTrap) Copy assignment operator called\n";

  if (this != &other) {
    ClapTrap::operator=(other);
  }

  return *this;
}

ScavTrap::~ScavTrap() { std::cout << "(ScavTrap) Destructor called\n"; }

void ScavTrap::attack(const std::string &target) {
  if (_hitPoints == 0 || _energyPoints == 0) {
    return;
  }

  _energyPoints -= 1;

  std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!" << '\n';
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << '\n';
}
