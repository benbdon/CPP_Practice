#include "std_lib_facilities.h"
 
enum class Month { 
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec 
};

class Date {  
public:
    class Invalid { };
    Date(int y, Month m, int d); // check for valid date and initialize
    Date(int y);
    void add_day(int n); // increase the Date by n days 
    Month month() { return m; } 
    int day() { return d; } 
    int year() { return y; } 
private:
    int y {2001};
    Month m {Month::jan};
    int d {1};
    bool is_valid();
};
Date::Date(int yy, Month mm, int dd) // constructor 
    :y{yy}, m{mm}, d{dd} // (member) initializer list
{ 
    if(!is_valid()) throw Invalid{}; // check for validity
}
Date::Date(int yy)
    :y{yy}
{
    if(!is_valid()) throw Invalid{};
}
void Date::add_day(int n) {
    // . . . 
} 
bool Date::is_valid() { // return true if date is valid
    if (int(m)<1 || 12<int(m)) return false; 
    // . . . 
}


void main() 
try {
    Date dx1 {1998, Month::mar, 3}; 
}
catch (Date::Invalid) {
    error("invalid date"); // error() defined in § 5.6.3
}