#include <cstdlib>
#include <ios>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

#include "Contact.h"
#include "PhoneBook.h"

int main() {
  PhoneBook phonebook;
  std::string command;

  while (true) {
    std::cout << "Enter a command (ADD, SEARCH, EXIT)\n> ";
    std::getline(std::cin, command);

    if (command == "EXIT" || std::cin.eof()) {
      return EXIT_SUCCESS;
    }

    try {
      if (command == "ADD") {
        phonebook.addContact(Contact::fromInput());
      } else if (command == "SEARCH") {
        phonebook.searchContact();
      }
    } catch (std::runtime_error &err) {
      std::cerr << "Error: " << err.what() << '\n';
    }

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}
