#pragma once

#include <cstddef>
#include <string>

#include "AMateria.h"
#include "ICharacter.h"

class Character : public ICharacter {
 public:
  Character();
  Character(const std::string& name);
  Character(const Character& other);
  Character& operator=(const Character& other);
  virtual ~Character();

  virtual const std::string& getName() const;
  virtual void equip(AMateria* materia);
  virtual void unequip(int index);
  virtual void use(int index, ICharacter& target);

 private:
  static const std::size_t s_inventorySize = 4;

  std::string m_name;
  AMateria* m_inventory[s_inventorySize];
};
