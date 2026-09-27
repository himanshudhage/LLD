#include <iostream>
using namespace std;

// 1. Strategy Interface
class PaymentStrategy
{
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentStrategy() {}
};

// 2. Concrete Strategy 1
class CardPayment : public PaymentStrategy
{
public:
    void pay(double amount) override
    {
        cout << "Paid Rs. " << amount << " using Credit Card" << endl;
    }
};

// 3. Concrete Strategy 2
class UpiPayment : public PaymentStrategy
{
public:
    void pay(double amount) override
    {
        cout << "Paid Rs. " << amount << " using UPI" << endl;
    }
};

class PaymentService
{
private:
    PaymentStrategy *strategy;

public:
    PaymentService(PaymentStrategy *strategy)
    {
        this->strategy = strategy;
    }
    void makePayment(double amount)
    {
        strategy->pay(amount);
    }
};

// 5. Client
int main()
{

    // Choose UPI strategy
    UpiPayment upi;
    PaymentService payment1(&upi);

    payment1.makePayment(500);

    // Choose Card strategy
    CardPayment card;
    PaymentService payment2(&card);

    payment2.makePayment(1000);

    return 0;
}