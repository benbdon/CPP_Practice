#include "std_lib_facilities.h" 
// try #2 doesn't work yet because 1-2-3 is parsed as 1-(2-3)

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
    switch(t.kind) { // see which kind of token it is
        case '+':
            return left + expression(); //read and evaluate a Term,
                                    // then do an add
        case '-':
            return left - expression(); // read and evaluate a Term,
                                    // then do a subtraction
        default:
            return left;
        }   
    }
}
double term(){ // deal with *, /, and % 

}
double primary(){ // deal with numbers and parentheses

} 

int main() {
}