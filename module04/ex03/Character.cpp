#include "Character.h"

#include <cstddef>
#include <string>

#include "AMateria.h"
#include "ICharacter.h"

Character::Character() : m_inventory() {}

Character::Character(const std::string& name) : m_name(name), m_inventory() {}

Character::Character(const Character& other)
    : m_name(other.m_name), m_inventory() {
  for (std::size_t i = 0; i < s_inventorySize; ++i) {
    if (!other.m_inventory[i]) {
      continue;
    }

    m_inventory[i] = other.m_inventory[i]->clone();
  }
}

Character& Character::operator=(const Character& other) {
  if (this != &other) {
    m_name = other.m_name;

    for (std::size_t i = 0; i < s_inventorySize; ++i) {
      if (!m_inventory[i]) {
        continue;
      }

      delete m_inventory[i];
      m_inventory[i] = other.m_inventory[i]->clone();
    }
  }

  return *this;
}

Character::~Character() {
  for (std::size_t i = 0; i < s_inventorySize; ++i) {
    delete m_inventory[i];
  }
}

const std::string& Character::getName() const { return m_name; }

void Character::equip(AMateria* materia) {
  for (std::size_t i = 0; i < s_inventorySize; ++i) {
    if (!m_inventory[i]) {
      m_inventory[i] = materia;
      return;
    }
  }
}

void Character::unequip(int index) {
  if (!m_inventory[index]) {
    return;
  }

  m_inventory[index] = NULL;
}

void Character::use(int index, ICharacter& target) {
  if (!m_inventory[index]) {
    return;
  }

  m_inventory[index]->use(target);
}
