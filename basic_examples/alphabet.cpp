/* This program prints the alphabet using a while loop*/

#include "std_lib_facilities.h"

int main() {
  char letter = 'a';
  while (letter != 'z' + 1) {
    cout << letter << '\t' << int(letter) << '\n';
    letter += 1;
  }
}
