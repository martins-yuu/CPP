#include "AMateria.h"

#include <string>

AMateria::AMateria() {}

AMateria::AMateria(const std::string& type) : m_type(type) {}

AMateria::AMateria(const AMateria& other) : m_type(other.m_type) {}

AMateria& AMateria::operator=(const AMateria&) { return *this; }

AMateria::~AMateria() {}

const std::string& AMateria::getType() const { return m_type; }

void AMateria::use(ICharacter&) {}
