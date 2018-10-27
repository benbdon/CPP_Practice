#include "std_lib_facilities.h"

int main() {
  cout << "Please enter your first name and age\n";
  string first_name = "???"; // ("???" means "don't know the name")
  int age = 0; // integer variable (0 means "don't know the age")
  cin >> first_name >> age; // read characters into first_name
  cout << "Hello, " << first_name << " (age " << age << ")\n";
}
