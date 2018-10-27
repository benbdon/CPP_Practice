/* basic_string_practice.cpp
Practice with variable assignment and concatenate */
#include "std_lib_facilities.h"

int main() {
  string previous;
  string current = " ";
  while (cin >> current) {
    if (current == previous)
      cout << "Repeated word: " << current << endl;
    previous = current;
  }
}
