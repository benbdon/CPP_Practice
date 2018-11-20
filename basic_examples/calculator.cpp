#include "std_lib_facilities.h" 

class Token {     // a very simple user-defined type
public:
    char kind;
    double value; 
};


int main() {
    Token t1 {'+'};
    Token t2 {'8',11.5};
}

Token get_token(); // function to read a token from cin 
vector<Token> tok; // we’ll put the tokens here 
int main() {
    while (cin) {
        Token t = get_token();
        tok.push_back(t);
    } 
    for (int i = 0; i < tok.size(); ++i) {
        if (tok[i].kind == '*') { // we found a multiply! 
            double d = tok[i - 1].value * tok[i + 1].value; 
    // now what? 
    } 
}