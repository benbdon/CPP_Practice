using namespace std;

// a very simplified vector of doubles 
class victor {
    int sz; // the size 
    double* elem; // a pointer to the elements 
public:
    victor(int s) 
        :sz{s}, elem{new double[s]} { /* . . . */ } // constructor 
    ~victor() { delete[] elem; } // destructor 

    int size() const { return sz; } // the current size

    double get(int n) const { return elem[n]; } // access: read 
    void set(int n,double v) { elem[n] = v; } // access: write 
};

int main() {
    victor<victor<double>>* p = new victor<victor<double>>(10);
    delete p;
}