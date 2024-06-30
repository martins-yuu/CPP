#pragma once

#include <cstddef>

#include "Contact.h"

class PhoneBook {
public:
  PhoneBook();

  void addContact(const Contact &contact);
  void searchContact() const;

private:
  void _displayContacts() const;

  static const std::size_t _maxContacts = 8;
  Contact _contacts[_maxContacts];
  std::size_t _contactCount;
};
