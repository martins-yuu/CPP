#include <iostream>

#include "ClapTrap.h"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(const std::string &name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "Name constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) {
  std::cout << "Copy constructor called\n";

  *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  std::cout << "Copy assignment operator called\n";

  if (this != &other) {
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
  }

  return *this;
}

ClapTrap::~ClapTrap() { std::cout << "Destructor called\n"; }

void ClapTrap::attack(const std::string &target) {
  if (_hitPoints == 0 || _energyPoints == 0) {
    return;
  }

  _energyPoints -= 1;

  std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!" << '\n';
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hitPoints == 0) {
    return;
  }

  if (amount > _hitPoints) {
    amount = _hitPoints;
  }

  _hitPoints -= amount;

  std::cout << "ClapTrap " << _name << " takes " << amount
            << " points of damage!" << '\n';
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_hitPoints == 0 || _energyPoints == 0) {
    return;
  }

  _energyPoints -= 1;
  _hitPoints += amount;

  std::cout << "ClapTrap " << _name << " is being repaired for " << amount
            << " points of damage!" << '\n';
}
