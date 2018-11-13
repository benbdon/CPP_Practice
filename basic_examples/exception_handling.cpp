#include "std_lib_facilities.h"

double some_function() {
    double d = 0;
    cin >> d; 
    if (!cin) 
        error("couldn't read a double in 'some_function()'"); 
}

int main() 
try {
    some_function();
    return 0; // 0 indicates success
}
catch(runtime_error& e) {
    cerr << "error:" << e.what() << endl;
    return 1; // 1 indicates run-time error
}
catch(exception& e) {
    cerr << "error:" << e.what() << endl;
    return 1; // 1 indicates some other type of error 
            //from std::exception 
}
catch(...) { //catch-all
    cerr << "Oops: unknown exception!" << endl;
    return 2; // 2 indicates error not included in std: exception
}

