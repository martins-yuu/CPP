#include <iostream>

#include "Fixed.h"

Fixed::Fixed() : _value(0) { std::cout << "Default constructor called\n"; }

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called\n";

  *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called\n";

  if (this != &other) {
    _value = other.getRawBits();
  }

  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called\n"; }

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called\n";

  return _value;
}

void Fixed::setRawBits(const int raw) {
  std::cout << "setRawBits member function called\n";

  _value = raw;
}
