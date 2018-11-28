#include "../std_lib_facilities.h"
#include "Chrono.h"

int main()
try { 
    Chrono::Date holiday{1978, Chrono::Month::jul, 4}; // initialization
    Chrono::Date d2{2010, Chrono::Month::oct, 10};
    Chrono::Day d=day_of_week(d2);
    cout << "holiday is " << holiday << " d2 is " << d2 << endl;
    keep_window_open();
    return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
} 
catch (...) { // catch all other exceptions
    cerr << "Exception: something went wrong\n";
    keep_window_open();
    return 2;
}