#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char *argv[]) {
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>\n";
    return EXIT_FAILURE;
  }

  const std::string filename = argv[1];
  const std::string s1 = argv[2];
  const std::string s2 = argv[3];

  std::stringstream buffer;
  {
    std::ifstream infile(filename.c_str());
    if (!infile) {
      std::cerr << "Error\n";
      return EXIT_FAILURE;
    }

    buffer << infile.rdbuf();
  }

  std::ofstream outfile((filename + ".replace").c_str());
  if (!outfile) {
    std::cerr << "Error\n";
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
