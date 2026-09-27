/*You have two pieces of code that need to work together, but their interfaces don't match.

The basic idea
Imagine you have:

A device with a plug that expects a certain socket.
A wall socket that provides a different type of connection.
You can't change either the device or the wall socket.
So you use an adapter in between.

Device  →  Adapter  →  Wall Socket
*/

#include <iostream>
using namespace std;

// Target
// Mobile phone expects a USB-C charger.
class USBTypeC
{

public:
    virtual void charger_with_typec() = 0;
    virtual ~USBTypeC();
};

// Adaptee
// Existing old charger supports Micro-USB.
class MicroUSBCharger
{
public:
    void charger_with_microusb()
    {
        cout << "Charging mobile using Micro-USB charger"
             << endl;
    }
};

// Adapter
// Converts Micro-USB interface to USB-C interface.
class ChargerAdapter : public USBTypeC
{
private:
    MicroUSBCharger *oldcharger;

public:
    ChargerAdapter(MicroUSBCharger *charger)
    {
        oldcharger = charger;
    }

    void charger_with_typec() override
    {
        oldcharger->charger_with_microusb();
    }
};

// Client
// Mobile phone only knows about USBTypeC.
class MobilePhone
{
public:
    void charge(USBTypeC *charger)
    {
        cout << "mobilephone connected...." << endl;
        charger->charger_with_typec();
    }
};

int main()
{
    MicroUSBCharger oldcharger;

    USBTypeC *adapter = new ChargerAdapter(&oldcharger);

    MobilePhone phone;
    phone.charge(adapter);

    delete adapter;

    return 0;
}
