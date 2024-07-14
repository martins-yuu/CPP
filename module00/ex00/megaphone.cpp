#include <cctype>
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  } else {
    for (int i = 1; i < argc; ++i) {
      const char *str = argv[i];
      for (int j = 0; str[j]; ++j) {
        std::cout << static_cast<char>(
            std::toupper(static_cast<unsigned char>(str[j])));
      }
    }
  }
  std::cout << '\n';
}
