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

  static Fixed &min(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);

  bool operator==(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;
  bool operator<(const Fixed &other) const;
  bool operator>(const Fixed &other) const;
  bool operator<=(const Fixed &other) const;
  bool operator>=(const Fixed &other) const;

  Fixed operator+(const Fixed &other) const;
  Fixed operator-(const Fixed &other) const;
  Fixed operator*(const Fixed &other) const;
  Fixed operator/(const Fixed &other) const;
  Fixed &operator++();
  Fixed operator++(int);
  Fixed &operator--();
  Fixed operator--(int);

  int getRawBits() const;
  void setRawBits(const int raw);

  float toFloat() const;
  int toInt() const;

private:
  static const int _fractionalBits = 8;

  int _value;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
