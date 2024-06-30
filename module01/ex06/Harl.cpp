#include <cstddef>
#include <iostream>
#include <string>

#include "Harl.h"

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

const char *Harl::_levelNames[] = {
    "DEBUG",
    "INFO",
    "WARNING",
    "ERROR",
};

void Harl::complain(Level level) {
  switch (level) {
  case Harl::debug:
    _debug();
    __attribute__((fallthrough));
  case Harl::info:
    _info();
    __attribute__((fallthrough));
  case Harl::warning:
    _warning();
    __attribute__((fallthrough));
  case Harl::error:
    _error();
    break;
  default:
    std::clog << "[ Probably complaining about insignificant problems ]\n";
  }
}

Harl::Level Harl::strToLevel(std::string level) {
  static const std::size_t levelCount =
      sizeof(_levelNames) / sizeof(*_levelNames);

  for (std::size_t i = 0; i < levelCount; ++i) {
    if (level == _levelNames[i]) {
      return static_cast<Level>(i);
    }
  }

  return Harl::none;
}

void Harl::_debug() {
  std::clog << "[ DEBUG ]\n"
            << "I love having extra bacon for my "
               "7XL-double-cheese-triple-pickle-specialketchup burger. "
               "I really do!"
            << '\n';
}

void Harl::_info() {
  std::clog << BLUE "[ INFO ]" RESET "\n"
            << "I cannot believe adding extra bacon costs more money.\n"
               "You didn’t put enough bacon in my burger! "
               "If you did, I wouldn’t be asking for more!"
            << '\n';
}

void Harl::_warning() {
  std::clog << YELLOW "[ WARNING ]" RESET "\n"
            << "I think I deserve to have some extra bacon for free.\n"
               "I’ve been coming for years whereas you started working here "
               "since last month."
            << '\n';
}

void Harl::_error() {
  std::clog << RED "[ ERROR ]" RESET "\n"
            << "This is unacceptable! I want to speak to the manager now."
            << '\n';
}
