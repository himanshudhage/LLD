#include <iostream>
using namespace std;

class Payment {
public:
    virtual void pay() = 0;
};

class CreditCard : public Payment {
public:
    void pay() override {
        cout << "Paid using Credit Card\n";
    }
};

class UPI : public Payment {
public:
    void pay() override {
        cout << "Paid using UPI\n";
    }
};

void makePayment(Payment* payment) {
    payment->pay();
}

int main() {
    CreditCard card;
    UPI upi;

    makePayment(&card);
    makePayment(&upi);
}

//Adding a new payment method does not require changing old code.