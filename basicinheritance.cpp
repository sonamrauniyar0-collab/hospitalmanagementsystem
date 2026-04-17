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
class AdvancedPrinter : public Printer {
public:
    void print(string text) {
        cout << "Advanced printing: " << text << endl;
    }
};
int main() {
    AdvancedPrinter obj;

    // Overriding
    obj.print("Hello");

    // Overloading (inherited)
    obj.print(100);

    return 0;
}