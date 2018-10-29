#include "std_lib_facilities.h"

int main() {
  //Get inputs from user
  cout << "Enter the name of the person you want to write to\n";
  string first_name;
  cin >> first_name;
  cout << "Enter the name of friend\n";
  string friend_name;
  cin >> friend_name;
  char friend_sex {0};
  cout << "Enter <m> if your friend is male and <f> if your friend is female\n";
  cin >> friend_sex;
  cout << "Enter the age of the letter recipient\n";
  int age;
  cin >> age;
  if(age < 0 | age > 100){
    simple_error("You're kidding");
  }

  //Write-out a letter
  cout << "Dear " << first_name << ",\n"
  << "\tHow are you? I am fine. I miss you. "
  << "Have you seen " << friend_name << " lately?"
  << "If you see " << friend_name << "please ask "
  << (friend_sex == 'm' ? "him ": "her ")
  << "to call me.\n"
  << "I hear you just had a birthday and you are " << age << " years old.";
  return 0;
}
