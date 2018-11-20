#include "std_lib_facilities.h" 
// try #3 doesn't work yet and is redundant with tests for + and get_token()

class Token {     // a very simple user-defined type
public:
    char kind;
    double value; 
};

Token get_token() { // read characters and compose tokens 

} 
double expression() { // deal with + and – 
    double left = term(); // read and evaluate an Expression
    Token t = get_token(); // get the next token
    while(t.kind == '+' || t.kind == '-') { // look for a + or -
        if(t.kind =='+')
            left += term(); // evaluate Term and add
        else
            left -= term(); // evaluate Term and subtract
        t = get_token();
        }
        return left;   // finally: no more + or -; return the answer
    }
}
double term(){ // deal with *, /, and % 

}
double primary(){ // deal with numbers and parentheses

} 

int main() {
}