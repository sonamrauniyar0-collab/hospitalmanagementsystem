#include <iostream>
using namespace std;

// ABSTRACT CLASS
class Animal {
public:
    // PURE VIRTUAL FUNCTION
    virtual void makeSound() = 0;
};

// DERIVED CLASS: Dog
class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Dog barks" << endl;
    }
};

// DERIVED CLASS: Cat
class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    // BASE CLASS POINTER
    Animal* a;

    // OBJECTS
    Dog d;
    Cat c;

    // RUNTIME POLYMORPHISM
    a = &d;
    a->makeSound();

    a = &c;
    a->makeSound();

    return 0;
}