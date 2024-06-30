#pragma once

#include <string>

class Brain {
 public:
  Brain();
  Brain(const Brain &);
  Brain &operator=(const Brain &);
  ~Brain();

 private:
  static const int s_ideaCount = 100;

  std::string m_ideas[s_ideaCount];
};
