#pragma once

class Fixed {
public:
  Fixed();
  Fixed(const Fixed &other);
  Fixed &operator=(const Fixed &other);
  ~Fixed();

  int getRawBits() const;
  void setRawBits(const int raw);

private:
  static const int _fractionalBits = 8;

  int _value;
};
