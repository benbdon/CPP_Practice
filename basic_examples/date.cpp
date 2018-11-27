#include "std_lib_facilities.h"
// simple Date (control access) 

class Date {  
public:
    class Invalid { };
    Date(int y, int m, int d); // check for valid date and initialize
    void add_day( int n); // increase the Date by n days 
    int month() { return m; } 
    int day() { return d; } 
    int year() { return y; } 
private:
    int y, m, d; // year, month, day
    bool is_valid();
};

Date::Date(int yy, int mm, int dd) // constructor 
    :y{yy}, m{mm}, d{dd} // (member) initializer list
{
        if(!is_valid()) throw Invalid{}; // check for validity
}
void Date::add_day(int n) {
    // . . . 
} 
int Date::month() { 
    return m; // not the member function, can’t access m
}

bool Date::is_valid() { // return true if date is valid
    if (m<1 || 12<m) return false; 
    // . . . 
}


void main() 
try {
    Date dxy {2004, 13, 1};
    cout << dxy << '\n'; // still need to explain what cout should do with out UDT
    dxy.add_day(2);
}
catch (Date::Invalid) {
    error("invalid date"); // error() defined in § 5.6.3
}