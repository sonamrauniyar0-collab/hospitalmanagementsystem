#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing shape" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() {
        cout << "Drawing Rectangle" << endl;
    }
};

int main() {
    Shape* s;
    Circle c;
    Rectangle r;

    s = &c;
    s->draw();   // late binding

    s = &r;
    s->draw();   // late binding

    return 0;
}