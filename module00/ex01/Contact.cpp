#include <iostream>
#include <ostream>
#include <stdexcept>

#include "Contact.h"

using std::string;

static void readField(string &field, const string &name);

Contact Contact::fromInput() {
  Contact contact;

  readField(contact._firstName, "first name");
  readField(contact._lastName, "last name");
  readField(contact._nickname, "nickname");
  readField(contact._phoneNumber, "phone number");
  readField(contact._darkestSecret, "darkest secret");

  return contact;
}

static void readField(string &field, const string &name) {
  std::cout << "Enter " << name << ": ";
  std::getline(std::cin, field);
  if (field.empty()) {
    throw std::runtime_error(name + " cannot be empty");
  }
}

const std::string &Contact::getFirstName() const { return _firstName; }

const std::string &Contact::getLastName() const { return _lastName; }

const std::string &Contact::getNickname() const { return _nickname; }

const std::string &Contact::getPhoneNumber() const { return _phoneNumber; }

const std::string &Contact::getDarkestSecret() const { return _darkestSecret; }

std::ostream &operator<<(std::ostream &os, const Contact &contact) {
  os << "First name:\t" << contact.getFirstName() << '\n'
     << "Last name:\t" << contact.getLastName() << '\n'
     << "Nickname:\t" << contact.getNickname() << '\n'
     << "Phone number:\t" << contact.getPhoneNumber() << '\n'
     << "Darkest secret:\t" << contact.getDarkestSecret() << '\n';

  return os;
}
