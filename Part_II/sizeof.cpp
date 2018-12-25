#include "../Part_I/std_lib_facilities.h"

int main() {
    cout << "the size of char is " << sizeof(char) << ' ' << sizeof ('a') << '\n';
    cout << "the size of int is "  << sizeof(int)  << ' ' << sizeof (2+2) << '\n';
    int* p = 0;
    cout << "the size of int* is "  << sizeof(int*) << ' ' << sizeof (p) << '\n';

    vector<int> v(1000);
    cout << "the size of vector<int>(1000) is "
         << sizeof(vector<int>) << ' ' << sizeof (v) << '\n';
}