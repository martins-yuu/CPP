#include <iostream>

int main() {
  using std::cout;

  const char *str = "HI THIS IS BRAIN";
  const char **stringPTR = &str;
  const char *&stringREF = str;

  cout << &str << '\n';
  cout << &*stringPTR << '\n';
  cout << &stringREF << '\n';

  cout << '\n';

  cout << str << '\n';
  cout << *stringPTR << '\n';
  cout << stringREF << '\n';
}
