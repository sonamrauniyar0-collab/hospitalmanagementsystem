#include <iostream>
using namespace std;

// ABSTRACT CLASS
class Shape {
public:
    // PURE VIRTUAL FUNCTION
    virtual void draw() = 0;
};

// DERIVED CLASS
class Circle : public Shape {
public:
    // FUNCTION OVERRIDING
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

// DERIVED CLASS
class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing Rectangle" << endl;
    }
};

int main() {
    // BASE CLASS POINTER
    Shape* s;

    Circle c;
    Rectangle r;

    // RUNTIME POLYMORPHISM
    s = &c;
    s->draw();  

    s = &r;
    s->draw();  

    return 0;
}