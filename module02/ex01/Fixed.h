#pragma once

#include <ostream>

class Fixed {
public:
  Fixed();
  Fixed(const int value);
  Fixed(const float value);
  Fixed(const Fixed &other);
  Fixed &operator=(const Fixed &other);
  ~Fixed();

  int getRawBits() const;
  void setRawBits(const int raw);

  float toFloat() const;
  int toInt() const;

private:
  static const int _fractionalBits = 8;

  int _value;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
