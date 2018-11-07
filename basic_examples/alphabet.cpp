/* This program prints the alphabet using a while loop*/

#include "std_lib_facilities.h"

int main() {
  for (char letter = 'a'; letter != 'z' + 1; ++letter) {
    cout << letter << '\t' << int(letter) << '\n';
  }
}
