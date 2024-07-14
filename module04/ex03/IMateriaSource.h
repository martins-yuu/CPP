#pragma once

#include "AMateria.h"

class IMateriaSource {
 public:
  virtual ~IMateriaSource() {}
  virtual void learnMateria(AMateria* materia) = 0;
  virtual AMateria* createMateria(const std::string& type) = 0;
};
