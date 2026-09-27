/*
Client: The code that needs an object and requests it from the factory.
Factory Class: The class responsible for creating and returning the appropriate object.
Object: The actual instance created by the factory (for example, a UPI object or a CreditCard object).
Concrete Classes: The classes (UPI, CreditCard, PayPal) from which the factory creates objects.
Product class : It provides a common interface for all payment methods.


Without Factory, the client creates and manages objects directly.
cons:
1. Tight Coupling
The client becomes dependent on specific classes.bcz of that Difficult to Change Implementations
If you later want to use CreditCard instead of UPI, you must modify the client code.

2. Difficult to Add New Types

With Factory, the client only requests an object, and the factory handles the creation
*/

#include <iostream>
#include <string>

using namespace std;

// product class
class Payment
{
public:
    virtual void pay() = 0;
    virtual ~Payment() {}
};

// concrete class
class UPI : public Payment
{
public:
    void pay() override
    {
        cout << "payment made using UPI" << endl;
    }
};

class CreditCard : public Payment
{
public:
    void pay() override
    {
        cout << "Payment made using credit card" << endl;
    }
};

class Paypal : public Payment
{
public:
    void pay() override
    {
        cout << "payment made using paypal" << endl;
    }
};

class PaymentFactory
{
public:
    Payment *getpayment(string payment_type)
    {
        if (payment_type == "UPI")
        {
            return new UPI();
        }
        else if (payment_type == "CreditCard")
        {
            return new CreditCard();
        }
        else if (payment_type == "PayPal")
        {
            return new Paypal();
        }

        return NULL;
    }
};

int main()
{
    PaymentFactory factory;
    Payment *payment1 = factory.getpayment("UPI");
    payment1->pay();

    Payment *payment2 = factory.getpayment("CreditCard");
    payment2->pay();

    Payment *payment3 = factory.getpayment("PayPal");
    payment3->pay();
    delete payment1;
    delete payment2;
    delete payment3;

    return 0;
}
