// Sonam Rauniyar
#include <iostream>
using namespace std;

class Printer {
public:
    void print(string text) {
        cout << "Printing text: " << text << endl;
    }
    void print(int number) {
        cout << "Printing number: " << number << endl;
    }
};
class ColorPrinter : public Printer {
public:
    void print(string text) {
        cout << "Printing in color: " << text << endl;
    }
};
int main() {
    Printer p;
    ColorPrinter cp;
    // Function Overloading
    p.print("Hello");
    p.print(100);
    // Method Overriding
    cp.print("Color Document");
    return 0;
}