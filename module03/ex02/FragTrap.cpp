#include <iostream>

#include "FragTrap.h"

FragTrap::FragTrap() : ClapTrap() {
  std::cout << "(FragTrap) Default constructor called\n";

  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
  std::cout << "(FragTrap) Name constructor called\n";

  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
  std::cout << "(FragTrap) Copy constructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
  std::cout << "(FragTrap) Copy assignment operator called\n";

  if (this != &other) {
    ClapTrap::operator=(other);
  }

  return *this;
}

FragTrap::~FragTrap() { std::cout << "(FragTrap) Destructor called\n"; }

void FragTrap::attack(const std::string &target) {
  if (_hitPoints == 0 || _energyPoints == 0) {
    return;
  }

  _energyPoints -= 1;

  std::cout << "FragTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!" << '\n';
}

void FragTrap::highFivesGuy() {
  std::cout << "FragTrap " << _name << " high fives a random guy." << '\n';
}
