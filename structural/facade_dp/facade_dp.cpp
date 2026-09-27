#include <iostream>
using namespace std;

class PaymentService
{
public:
    void make_payment()
    {
        cout << "payment successful" << endl;
    }
};

class InventryService
{
public:
    void update_inventry()
    {
        cout << "inventry updated" << endl;
    }
};

class NotificationServices
{
public:
    void send_notification()
    {
        cout << "notification has been sent" << endl;
    }
};

// -----------------------------
// 4. Facade Class
// -----------------------------
// This class hides the complexity of
// PaymentService, InventoryService,
// and NotificationService.
//
// The client only needs to call
// placeOrder().
class OrderFacade
{

private:
    PaymentService ps;
    InventryService is;
    NotificationServices ns;

public:
    void place_order()
    {
        ps.make_payment();
        is.update_inventry();
        ns.send_notification();

        cout << "order placed successfully" << endl;
    }
};

int main()
{
    OrderFacade orderFacade;
    orderFacade.place_order();
}