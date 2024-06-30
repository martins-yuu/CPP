#pragma once

#include <string>

class Harl {
public:
  enum Level {
    none = -1,
    debug,
    info,
    warning,
    error,
  };

  static Level strToLevel(std::string level);

  void complain(Level level);

private:
  void _debug();
  void _info();
  void _warning();
  void _error();

  static const char *_levelNames[];
};
