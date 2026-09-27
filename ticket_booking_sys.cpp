//dependency

#include<iostream>
using namespace std;

class SeatValidator{
    public:

    bool check_seat(string event_id , string seat_no){

        cout<<"checking seat "<<seat_no<<" for event "<<event_id<<endl;
        return true;
    }

};

class PaymentProcessor{
    public:
    bool make_payment(string email , double amount){
         cout << "Payment of $" << amount << " received from " << email << endl;

         return true;
    }
};

class QrCodeGenerator{
    public:
    string create_qr(string event_id , string seat_no){
        string qr = "QR-" + event_id + "-" + seat_no;

        cout<<"QR code: "<<qr<<endl;

        return qr;
    }
};

class EmailService{
    public:
    void send_email(string email , string qr){
        cout<<"confirmation email sent to "<<email<<endl;
        cout<<"OR Code: "<<qr<<endl;
    }
};

class TicketBookingService{
    public:
    bool book_ticket(string event_id , string seat_no , string email , double amount , SeatValidator &seat , PaymentProcessor &payment , QrCodeGenerator &qr , EmailService &mail){

        if(!seat.check_seat(event_id,seat_no)){
            cout<<"seat not avaliable!"<<endl;
            return false;
        }

        if(!payment.make_payment(email,amount)){
            cout<<"payment failed"<<endl;
            return false;
        }

        string code = qr.create_qr(event_id,seat_no);

        mail.send_email(email,code);

        cout<<"ticket booked successfully!"<<endl;

        return true;
    }
};

int main(){
    SeatValidator seat;
    PaymentProcessor payment;
    QrCodeGenerator qr;
    EmailService mail;
    TicketBookingService booking;

    booking.book_ticket("conf_25","a12","alice@example.com",99.99,seat,payment,qr,mail);

    return 0;
}