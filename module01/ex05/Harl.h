#pragma once

#include <string>

class Harl {
public:
  void complain(std::string level);

private:
  typedef void (Harl::*_complaintFunc)();

  void _debug();
  void _info();
  void _warning();
  void _error();

  static const char *_levelNames[];
  static const _complaintFunc _complaintFuncs[];
};
