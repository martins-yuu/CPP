#pragma once

#include <string>

#include "AMateria.h"

class AMateria;

class ICharacter {
 public:
  virtual ~ICharacter() {}
  const virtual std::string& getName() const = 0;
  virtual void equip(AMateria* materia) = 0;
  virtual void unequip(int index) = 0;
  virtual void use(int index, ICharacter& target) = 0;
};
