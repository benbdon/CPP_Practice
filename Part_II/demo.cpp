#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>

using namespace std;

int main() {
    Fl_Window win(800,600,"demo");
    win.begin();
    Fl_Button but(20,20,60,25,"New");
    win.end();
    win.show();

    return Fl::run();
}