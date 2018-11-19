#include "std_lib_facilities.h"

int main()
try { 
    //YOUR CODE GOES HERE
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
