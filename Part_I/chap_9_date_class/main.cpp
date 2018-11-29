#include "../std_lib_facilities.h"
#include "Chrono.h"

int main()
try { 
    Chrono::Date today {1978, Chrono::Month::jun, 25};
    Chrono::Date tomorrow = today;
    Chrono::Date month_later = today;
    tomorrow.add_day(1);
    month_later.add_month(14);
    cout << "Today: " << today << endl;
    cout << "Tomorrow: " << tomorrow << endl;
    cout << "Month later: " << month_later << endl;
    
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