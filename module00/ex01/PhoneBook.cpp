#include <cstddef>
#include <iomanip>
#include <iostream>
#include <limits>
#include <ostream>
#include <stdexcept>
#include <string>

#include "Contact.h"
#include "PhoneBook.h"

PhoneBook::PhoneBook() : _contactCount(0) {}

void PhoneBook::addContact(const Contact &contact) {
  static std::size_t index = 0;

  _contacts[index % _maxContacts] = contact;
  ++index;
  _contactCount = std::min(_contactCount + 1, _maxContacts);
}

void PhoneBook::searchContact() const {
  _displayContacts();

  std::cout << "Enter the index of the entry to display: ";
  std::size_t index;
  std::cin >> index;

  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    throw std::runtime_error("Invalid input");
  }

  if (index >= _contactCount) {
    throw std::runtime_error("Contact not found");
  }

  std::cout << _contacts[index];
}

void PhoneBook::_displayContacts() const {
  static const std::size_t fieldWidth = 10;

  std::cout << "+----------+----------+----------+----------+\n"
               "|     Index|First Name| Last Name|  Nickname|\n"
               "+----------+----------+----------+----------+\n";
  for (std::size_t i = 0; i < _contactCount; ++i) {
    const std::string fields[] = {
        _contacts[i].getFirstName(),
        _contacts[i].getLastName(),
        _contacts[i].getNickname(),
    };
    std::size_t fieldCount = sizeof(fields) / sizeof(*fields);

    std::cout << '|' << std::setw(fieldWidth) << i;
    for (std::size_t j = 0; j < fieldCount; ++j) {
      std::cout << '|';
      if (fields[j].length() > fieldWidth) {
        std::cout << fields[j].substr(0, fieldWidth - 1) + '.';
      } else {
        std::cout << std::setw(fieldWidth) << fields[j];
      }
    }
    std::cout << "|\n"
                 "+----------+----------+----------+----------+\n";
  }
}
