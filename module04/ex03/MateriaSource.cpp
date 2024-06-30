#include "MateriaSource.h"

#include <cstddef>

#include "AMateria.h"

MateriaSource::MateriaSource() : m_materias() {}

MateriaSource::MateriaSource(const MateriaSource& other) { *this = other; }

MateriaSource& MateriaSource::operator=(MateriaSource const& other) {
  if (this != &other) {
    for (std::size_t i = 0; i < s_materiaCount; ++i) {
      delete m_materias[i];
      m_materias[i] = other.m_materias[i];
    }
  }

  return *this;
}

MateriaSource::~MateriaSource() {
  for (std::size_t i = 0; i < s_materiaCount; ++i) {
    delete m_materias[i];
  }
}

void MateriaSource::learnMateria(AMateria* materia) {
  for (std::size_t i = 0; i < s_materiaCount; ++i) {
    if (!m_materias[i]) {
      m_materias[i] = materia;
      break;
    }
  }
}

AMateria* MateriaSource::createMateria(const std::string& type) {
  for (std::size_t i = 0; i < s_materiaCount; ++i) {
    if (m_materias[i] && m_materias[i]->getType() == type) {
      return m_materias[i]->clone();
    }
  }
  return NULL;
}
