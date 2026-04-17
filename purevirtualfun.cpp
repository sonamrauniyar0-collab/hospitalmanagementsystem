#include <iostream>
#include <vector>
using namespace std;

// ABSTRACT BASE CLASS
class Shape {
public:
    // PURE VIRTUAL FUNCTION
    virtual double calculateArea() = 0;
};

// DERIVED CLASS: Rectangle
class Rectangle : public Shape {
private:
    double length, width;

public:
    void setData(double l, double w) {
        length = l;
        width = w;
    }

    double calculateArea() override {
        return length * width;
    }
};

// DERIVED CLASS: Circle
class Circle : public Shape {
private:
    double radius;

public:
    void setData(double r) {
        radius = r;
    }

    double calculateArea() override {
        return 3.1416 * radius * radius;
    }
};

int main() {
    // CREATE OBJECTS
    Rectangle rect;
    Circle circ;

    // SET VALUES
    rect.setData(10, 5);
    circ.setData(7);

    // VECTOR OF BASE CLASS POINTERS
    vector<Shape*> shapes;

    shapes.push_back(&rect);
    shapes.push_back(&circ);

    // RUNTIME POLYMORPHISM
    for (Shape* s : shapes) {
        cout << "Area: " << s->calculateArea() << endl;
    }

    return 0;
}