#pragma once

#include <ostream>
#include <string>

class Contact {
public:
  static Contact fromInput();

  const std::string &getFirstName() const;
  const std::string &getLastName() const;
  const std::string &getNickname() const;
  const std::string &getPhoneNumber() const;
  const std::string &getDarkestSecret() const;

private:
  std::string _firstName;
  std::string _lastName;
  std::string _nickname;
  std::string _phoneNumber;
  std::string _darkestSecret;
};

std::ostream &operator<<(std::ostream &os, const Contact &contact);
