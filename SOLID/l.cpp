#include <iostream>
using namespace std;

class Bird {
public:
    virtual void move() = 0;
};

class Sparrow : public Bird {
public:
    void move() override {
        cout << "Flying\n";
    }
};

class Penguin : public Bird {
public:
    void move() override {
        cout << "Walking\n";
    }
};

void makeMove(Bird* bird) {
    bird->move();
}

int main() {
    Sparrow s;
    Penguin p;

    makeMove(&s);
    makeMove(&p);
}

// Both birds can be used through the Bird type.