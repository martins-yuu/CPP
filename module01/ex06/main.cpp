#include <cstdlib>
#include <iostream>

#include "Harl.h"

int main(int argc, char *argv[]) {
  Harl harl;

  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <level>\n";
    return EXIT_FAILURE;
  }

  harl.complain(Harl::strToLevel(argv[1]));

  return EXIT_SUCCESS;
}
