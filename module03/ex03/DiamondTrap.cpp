#include <iostream>

#include "DiamondTrap.h"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() {
  std::cout << "(DiamondTrap) Default constructor called\n";

  ClapTrap::_name = _name + "_clap_name";
  _hitPoints = FragTrap::_hitPoints;
  _energyPoints = ScavTrap::_energyPoints;
  _attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const std::string &name) : _name(name) {
  std::cout << "(DiamondTrap) Name constructor called\n";

  ClapTrap::_name = _name + "_clap_name";
  _hitPoints = FragTrap::_hitPoints;
  _energyPoints = ScavTrap::_energyPoints;
  _attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other) {
  std::cout << "(DiamondTrap) Copy constructor called\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
  std::cout << "(DiamondTrap) Copy assignment operator called\n";

  if (this != &other) {
    ClapTrap::operator=(other);
    _name = other._name;
  }

  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "(DiamondTrap) Destructor called\n";
}

void DiamondTrap::attack(const std::string &target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
  std::cout << "DiamondTrap name: " << _name << '\n';
  std::cout << "ClapTrap name: " << ClapTrap::_name << '\n';
}
