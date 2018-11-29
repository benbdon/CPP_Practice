#include "std_lib_facilities.h"

int main() {
    int i = 7;
    int& r = i; // r is a new name for memory
    r = 9;
    cout << r << i << endl;
    i = 10;
    cout << r << i << endl;
}