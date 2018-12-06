#include "../Part_I/std_lib_facilities.h"

int main() {
    cout<<1234.56789<<"\t\t(defaultfloat)\n" // \t\t to line up columns
    <<fixed<<1234.56789<<"\t(fixed)\n"
    <<scientific<<1234.56789<<"\t(scientific)\n";
}