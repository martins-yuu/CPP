#pragma once

#include <string>

class Zombie {
public:
  Zombie();
  ~Zombie();

  void announce();

  std::string _name;
};

Zombie *zombieHorde(int n, std::string name);
