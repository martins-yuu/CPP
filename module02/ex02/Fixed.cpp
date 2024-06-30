#include <cmath>
#include <iostream>

#include "Fixed.h"

Fixed::Fixed() : _value(0) { std::cout << "Default constructor called\n"; }

Fixed::Fixed(const int value) : _value(value << _fractionalBits) {
  std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float value)
    : _value(roundf(value * (1 << _fractionalBits))) {
  std::cout << "Float constructor called\n";
}

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

Fixed &Fixed::min(Fixed &a, Fixed &b) { return a < b ? a : b; }

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) { return a > b ? a : b; }

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return a > b ? a : b;
}

bool Fixed::operator==(const Fixed &other) const {
  return _value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const { return !(*this == other); }

bool Fixed::operator<(const Fixed &other) const {
  return _value < other._value;
}

bool Fixed::operator>(const Fixed &other) const { return other < *this; }

bool Fixed::operator<=(const Fixed &other) const { return !(*this > other); }

bool Fixed::operator>=(const Fixed &other) const { return !(*this < other); }

Fixed Fixed::operator+(const Fixed &other) const {
  return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
  return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
  return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
  return Fixed(toFloat() / other.toFloat());
}

Fixed &Fixed::operator++() {
  ++_value;

  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);

  ++(*this);

  return tmp;
}

Fixed &Fixed::operator--() {
  --_value;

  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);

  --(*this);

  return tmp;
}

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called\n";

  return _value;
}

void Fixed::setRawBits(const int raw) {
  std::cout << "setRawBits member function called\n";

  _value = raw;
}

float Fixed::toFloat() const {
  return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt() const { return _value >> _fractionalBits; }

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  return os << fixed.toFloat();
}
