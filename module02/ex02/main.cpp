#include <iostream>

#include "Fixed.h"

int main(void) {
  Fixed a;
  const Fixed b(Fixed(5.05f) * Fixed(2));

  std::cout << a << '\n'
            << ++a << '\n'
            << a << '\n'
            << a++ << '\n'
            << a << '\n'
            << b << '\n'
            << Fixed::max(a, b) << '\n';
}
