
//association

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Forward declaration because Doctor and Patient
// are used before they are fully defined.
class Doctor;
class Patient;

//---------------------- Room Class ----------------------
class Room {
public:
    string number;
    int floor;

    // Constructor to initialize room details
    Room(string n, int f) {
        number = n;
        floor = f;
    }
};

//------------------- Appointment Class -------------------
class Appointment {
public:
    Doctor* doctor;     // Pointer to Doctor
    Patient* patient;   // Pointer to Patient
    Room* room;         // Pointer to Room
    string time;        // Appointment time

    // Constructor declaration
    Appointment(Doctor* d, Patient* p, Room* r, string t);
};

//---------------------- Doctor Class ----------------------
class Doctor {
public:
    string name;
    string specialization;

    // Stores all appointments of this doctor
    vector<Appointment*> appointments;

    // Constructor
    Doctor(string n, string s) {
        name = n;
        specialization = s;
    }

    // Adds a new appointment to the doctor's list
    void addAppointment(Appointment* a) {
        appointments.push_back(a);
    }
};

//---------------------- Patient Class ----------------------
class Patient {
public:
    string name;

    // Stores all appointments of this patient
    vector<Appointment*> appointments;

    // Constructor
    Patient(string n) {
        name = n;
    }

    // Adds a new appointment to the patient's list
    void addAppointment(Appointment* a) {
        appointments.push_back(a);
    }
};

//--------------- Appointment Constructor -----------------
Appointment::Appointment(Doctor* d, Patient* p, Room* r, string t) {

    // Store doctor, patient, room and time
    doctor = d;
    patient = p;
    room = r;
    time = t;

    // Automatically register this appointment
    // with the doctor and patient
    doctor->addAppointment(this);
    patient->addAppointment(this);
}

//--------------------------- Main --------------------------
int main() {

    // Create Doctor objects
    Doctor d1("Dr. Smith", "Cardiology");
    Doctor d2("Dr. Patel", "Neurology");

    // Create Patient objects
    Patient p1("Alice");
    Patient p2("Bob");

    // Create Room objects
    Room r1("101", 1);
    Room r2("205", 2);

    // Create appointments
    // These automatically get added to both
    // doctor and patient appointment lists.
    Appointment a1(&d1, &p1, &r1, "9:00 AM");
    Appointment a2(&d1, &p2, &r1, "10:00 AM");
    Appointment a3(&d2, &p1, &r2, "2:00 PM");

    // Display Dr. Smith's schedule
    cout << d1.name << "'s Schedule\n";

    // Loop through all appointments of Dr. Smith
    for (auto a : d1.appointments) {
        cout << a->time
             << " - "
             << a->patient->name
             << " (Room "
             << a->room->number
             << ")\n";
    }
    cout << endl;

    // Display Alice's appointments
    cout << p1.name << "'s Appointments\n";

    // Loop through all appointments of Alice
    for (auto a : p1.appointments) {
        cout << a->time
             << " - "
             << a->doctor->name
             << " ("
             << a->doctor->specialization
             << ")\n";
    }

    return 0;
}