#include "std_lib_facilities.h" 
// try #5 seems to work, but doesn't handle the divide by zero case gracefully

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
    while(true) { 
        switch(t.kind) {
            case '+':
                left += term(); // evaluate Term and add
                t = get_token();
                break;
            case '-':
                left -= term(); // evaluate Term and subtract
                t = get_token();
                break;
            default:
                return left;
        }
        return left;   // finally: no more + or -; return the answer
    }
}
double term(){ // deal with *, /, and % 
    double left = primary();
    Token t = get_token();
    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = get_token();
            break;
        case '/':
            left /= primary();
            t = get_token();
            break;
        default:
            return left;
        }
    }
}
double primary(){ // deal with numbers and parentheses

} 

int main() {
}