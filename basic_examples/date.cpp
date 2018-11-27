#include "std_lib_facilities.h"
 
enum class Month { 
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec 
};

class Year {
    static constexpr int min = 1800;
    static constexpr int max = 2200;
public:
    class Invalid { };
    Year(int x)
        : y{x} {
            if (x<min || max<=x) throw Invalid{};
        }
        int year() {
            return y;
        }
private:
    int y;
};

class Date {  
public:
    class Invalid { };
    Date(Year y, Month m, int d); // check for valid date and initialize
    void add_day( int n); // increase the Date by n days 
    Month month() { return m; } 
    int day() { return d; } 
    Year year() { return y; } 
private:
    Year y;
    Month m;
    int d;
    bool is_valid();
};

Date::Date(Year yy, Month mm, int dd) // constructor 
    :y{yy}, m{mm}, d{dd} // (member) initializer list
{
        if(!is_valid()) throw Invalid{}; // check for validity
}
void Date::add_day(int n) {
    // . . . 
} 
Month Date::month() { 
    return m;
}

bool Date::is_valid() { // return true if date is valid
    if (int(m)<1 || 12<int(m)) return false; 
    // . . . 
}


void main() 
try {
Date dx1 {Year{1998}, 4, 3}; // error: 2nd argument not a Month 
Date dx2 {Year{ 1998}, 4, Month:: mar}; // error: 2nd argument not a Month 
Date dx2 {4, Month:: mar, Year{ 1998}}; // error: 1st argument not a Year 
Date dx2 {Month:: mar, 4, Year{ 1998}}; // error: 2nd argument not a Month 
Date dx3 {Year{ 1998}, Month:: mar, 30}; // OK

}
catch (Date::Invalid) {
    error("invalid date"); // error() defined in § 5.6.3
}