/* basic_string_practice.cpp
Practice with variable assignment and concatenate */
#include "std_lib_facilities.h"

int main() {
  string a = "alpha";
  cout << "a = " << a << endl;
  a = "beta";
  cout << "a = " << a << endl;
  string b = a;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  b = a + "gamma";
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  a = a + "delta";
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  return 0;
}
