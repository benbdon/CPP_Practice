/* This program prints the alphabet using a while loop*/

#include "std_lib_facilities.h"

int main() {
  vector<string> words;
  string disliked = "pineapple";
  string disliked2 = "grapefruit";

  for(string temp; cin>>temp; ) // read whitespace-separated words
    if(temp == disliked || temp == disliked2)
      words.push_back("BLEEP");
    else
      words.push_back(temp); // put into vector
  cout << "Number of words: " << words.size() << '\n';

  sort(words); //sort the words

  for(int i = 0; i < words.size(); ++i)
    if(i==0 || words[i-1] != words[i])
      cout << words[i] << '\n';
}
