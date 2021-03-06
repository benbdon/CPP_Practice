#include "../std_lib_facilities.h" 

/*
    Simple calculator 

    Revision history:
        Revised by Ben Don November 2018
        Revised by Bjarne Stroustrup November 2013 
        Originally written by Bjarne Stroustrup 
            (bs@cs.tamu.edu) Spring 2004. 

    This program implements a basic expression calculator. 
    Input from cin; output to cout. 
    
    The grammar for input is: 

    Calculation: 
        Statement
        Print 
        Quit
        Calculation Statment

    Statement:
        Declaration
        Expression

    Declaration:
        "let" Name "=" Expression

    Print:
        ;

    Quit:
        q

    Expression:
        Term
        Expression + Term
        Expression - Term
    Term:
        Primary
        Term * Primary
        Term / Primary
        Term % Primary
    Primary:
        Number
        ( Expression )
        - Primary
        + Primary
    Number:
        floating-point-literal

    Input comes from cin through the Token_stream called ts.
*/



//---

constexpr char number = '8';    // t.kind==number means that t is a number Token
constexpr char quit = 'q'; // t.kind == quit means that t is a quit Token 
constexpr char print = ';'; // t.kind == print means that t is a print Token
constexpr char name = 'a'; // name token 
constexpr char let = 'L'; // declaration token 
const string declkey = "let"; // declaration keyword
const string prompt = "> "; 
const string result = "= "; // used to indicate that what follows is a result

//---

class Token {
public:
    char kind;  //what kind of token
    double value; // for numbers: a value
    string name; // 
    Token()                     :kind{0}                {} 
    Token(char ch)              :kind{ch}               {} 
    Token(char ch, double val)  :kind{ch}, value{val}   {} 
    Token(char ch, string n)    :kind{ch}, name{n}      {} 
};

//---

class Token_stream {
public:
    Token get();        // get a Token
    void putback(Token t); // put a Token back
    void ignore(char c); // discard characters up to and including a c
private:
    bool full {false};      // is there a Token in the buffer?
    Token buffer;       // here is where we keep a Token put back using putback()
};

//---

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t) {
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//---

Token Token_stream::get() {
    if (full) {       // check if we already have a Token ready
        full = false; 
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)
    
    switch (ch) {
        case quit:
        case print:
        case '(': 
        case ')': 
        case '+': 
        case '-': 
        case '*': 
        case '/': 
        case '%':
        case '=':
            return Token(ch); // let each character represent itself
        case '.': // a floating-point literal can start with a dot
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9': { // numeric literal    
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return Token{number,val};
        } default:
            if (isalpha(ch)) {
                string s;
                s = ch; // books says s += ch
                while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
                cin.putback(ch);
                if (s == declkey) return Token{let}; //declaration keyword
                return Token{name,s};
            }
            error("Bad token");
    }
}

//---

void Token_stream::ignore(char c) { // c represents the kind of Token
    // first look in buffer:
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;

    // now search input:
    char ch = 0;
    while (cin >> ch)
        if(ch == c) return;
}

//---

Token_stream ts; // provides get() and putback()

//---

class Variable {
public:
    string name;
    double value;
    Variable (string n, double v): name(n), value(v) {}
};

//---


vector<Variable> var_table;

//---

double get_value(string s) {
    for (const Variable& v : var_table)
        if (v.name == s) return v.value;
    error("get: undefined variable ", s);
}

//---

void set_value(string s, double d) {
    for (Variable& v : var_table) 
        if (v.name == s) {
            v.value = d;
            return;
        }
    error("set: undefined variable",s);
}

//---

bool is_declared(string var) {
    // is var already in var_table?
    for (const Variable& v : var_table)
        if (v.name == var) return true;
    return false;
}

//---

double define_name(string var, double val) {
    // add {var, val} to var_table
    if (is_declared(var)) error(var," declared twice");
    var_table.push_back(Variable{var,val});
    return val;
}

//---

double expression(Token_stream& ts); // declaration so that primary() can call expression()

//---

// deal with numbers and parentheses
double primary(Token_stream& ts){ 
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
        {   double d = expression(ts);
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
    case number:
        return t.value;  // return the number's value
    case name:
        return get_value(t.name); // return the variable's name
    case '-': 
        return - primary(ts); 
    case '+': 
        return primary(ts); 
    default:
        error("primary expected");
    }
}

//---

// deal with *, /, and %
double term(Token_stream& ts) {  
    double left = primary(ts);
    Token t = ts.get(); // get the next Token from the Token stream
   
    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary(ts);
            t = ts.get();
            break;
        case '/': {
            double d = primary(ts);
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        } case '%': {
            double d = primary(ts);
            if (d == 0) error("%: divide by zero"); 
            left = fmod(left, d);
            t = ts.get(); 
            break;
        } default:
            ts.putback(t); // put t back into the Token stream
            return left;
        }
    }
}

//---

double expression(Token_stream& ts) { // deal with + and – 
    double left = term(ts); // read and evaluate an Term
    Token t = ts.get(); // get the next Token from the Token stream

    while(true) { 
        switch(t.kind) {
        case '+':
            left += term(ts); // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term(ts); // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}

//---

double declaration(Token_stream& ts) {
    // handle: name = expression 
    // declare a variable called "name" with the initial value "expression"
    Token t = ts.get(); 
    if (t.kind != name) error ("name expected in declaration"); 
    string var_name = t.name; 
    
    Token t2 = ts.get(); 
    if (t2. kind != '=') error("= missing in declaration of ", var_name);
    
    double d = expression(ts);
    define_name(var_name,d); 
    return d;
}

//---

double statement(Token_stream& ts) {
    Token t = ts.get(); 
    switch (t.kind) {
        case let:
            return declaration(ts); 
        default: 
            ts.putback(t);
            return expression(ts); 
    }
}

//---

void clean_up_mess() { // naive 
    ts.ignore(print);
}

//---

void calculate(Token_stream& ts) {
    while (cin) 
    try {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print) t = ts.get(); // first discard all "prints" 
        if (t.kind == quit) return; 
        ts.putback(t); 
        cout << result << statement(ts) << '\n';
    }
    catch (exception& e) { 
        cerr << e.what() << '\n'; // write error message 
        clean_up_mess();
    }
}

//---

int main()
try {
    cout << "Welcome to our simple calculator.\nPlease enter expressions using floating-point numbers.\n";

    // predefine names: 
    define_name("pi", 3.1415926535);
    define_name("e", 2.7182818284);

    calculate(ts);
    keep_window_open();
    return 0;
}
catch (runtime_error& e) {
    cerr << e.what() << '\n'; 
    keep_window_open("~~"); 
    return 1;
}
catch (...) {
    cerr << "exception \n";
    keep_window_open("~~");
    return 2;
}