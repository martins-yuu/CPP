#pragma once

#include "IMateriaSource.h"

class MateriaSource : public IMateriaSource {
 public:
  MateriaSource();
  MateriaSource(const MateriaSource& other);
  MateriaSource& operator=(const MateriaSource& other);
  virtual ~MateriaSource();

  virtual void learnMateria(AMateria* materia);
  virtual AMateria* createMateria(const std::string& type);

 private:
  static const std::size_t s_materiaCount = 4;

  AMateria* m_materias[s_materiaCount];
};
