#include "../Part_I/std_lib_facilities.h"

int main()
try { 
    //part 7
    /*
    int birth_year = 1987;
    int current_year = 2018;
    cout<<showbase<<birth_year<<"\t(decimal)\n"
    <<hex<<birth_year<<"\t(hexadecimal\n"
    <<oct<<birth_year<<"\t(octal)\n"
    <<dec<<current_year-birth_year<<endl; 
    */
    //part 9
    /*
    cout<<defaultfloat<<1234567.89<<'\n'
    <<fixed<<1234567.89<<'\n'
    <<scientific<<1234567.89<<endl;
    */

    cout<<"Ben\tDon\t|\t(yyy)xxx-xxxx\t|\tbenxxx@yahoo.com"<<'\n'
    <<"Sponge\tBob\t|\t(yyy)xxx-xxxx\t|\txxx@yahoo.com"<<endl;

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