#include "../Part_I/std_lib_facilities.h"

// Feed this program the following line as a test...
// "There are only two kinds of languages: languages that people complain about, and languages that people don't use."

class Punct_stream { // like an istream, but the user can add to 
            // the set of whitespace characters 
public: 
    Punct_stream(istream& is) : source{is}, sensitive{true} { } 
    void whitespace(const string& s) {// make s the whitespace set  
        white = s; 
    } 
    void add_white(char c) { // add to the whitespace set
        white+=c; 
    } 
    bool is_whitespace(char c); // is c in the whitespace set? 
    void case_sensitive(bool b) { sensitive = b; }
    bool is_case_sensitive() { return sensitive; } 
    Punct_stream& operator>>(string& s);
    operator bool(); 
private: 
    istream& source; // character source 
    istringstream buffer; // we let buffer do our formatting 
    string white; // characters considered “whitespace” 
    bool sensitive; // is the stream case-sensitive? 
};

Punct_stream& Punct_stream::operator>>(string& s) {
    while (!(buffer>>s)) { // try to read from buffer 
        if (buffer.bad() || !source.good()) return *this; 
        buffer.clear();

        string line; 
        getline(source, line); // get a line from source 
        
        // do character replacement as needed: 
        for (char& ch : line) {
            if (is_whitespace(ch)) 
                ch = ' '; // to space else 
            if (!sensitive) 
                ch = tolower(ch); // to lower case 
        }
        buffer.str(line); // put string into stream 
    } 
    return *this;
}

bool Punct_stream::is_whitespace(char c) {
    for (char w : white) 
        if (c == w) return true; 
    return false;
}

Punct_stream::operator bool() {
    return !(source.fail() || source.bad()) && buffer.good(); 
}

int main(){
    Punct_stream ps {cin}; // use cin as the inputstream
    ps.whitespace(";:,.?!()\"{}<>/&$@#%^*|~");
    ps.case_sensitive(false); // not case-sensitive
    ps.case_sensitive(false); 
    
    cout<<"please enter words\n"; 
    vector<string> vs; 
    for (string word; ps>>word; )
        vs.push_back(word); // read words

    sort(vs.begin(), vs.end()); // sort in lexicographical order 
    for (int i=0; i<vs.size(); ++i) // write dictionary 
        if (i == 0 || vs[i]!=vs[i-1]) cout<<vs[i]<<'\n';

}
