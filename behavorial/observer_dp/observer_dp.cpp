#include <iostream>
#include <vector>
using namespace std;

// Observer Interface
class Observer {
public:
    virtual void update(string video) = 0;
    virtual ~Observer() {}
};

// Concrete Observer
class Subscriber : public Observer {
private:
    string name;

public:
    Subscriber(string name) {
        this->name = name;
    }

    void update(string video) override {
        cout << name << " got notification: New video - "
             << video << endl;
    }
};

// Subject
class YouTubeChannel {
private:
    vector<Observer*> subscribers;

public:

    // Add subscriber
    void subscribe(Observer* observer) {
        subscribers.push_back(observer);
    }

    // Remove subscriber
    void unsubscribe(Observer* observer) {
        // Simple version: not implemented
    }

    // Notify all subscribers
    void notify(string video) {
        for (Observer* observer : subscribers) {
            observer->update(video);
        }
    }

    // Upload video
    void uploadVideo(string video) {
        cout << "New video uploaded: " << video << endl;

        notify(video);
    }
};

int main() {

    // Create channel
    YouTubeChannel channel;

    // Create subscribers
    Subscriber user1("Rahul");
    Subscriber user2("Amit");
    Subscriber user3("Priya");

    // Subscribe users
    channel.subscribe(&user1);
    channel.subscribe(&user2);
    channel.subscribe(&user3);

    // Upload video
    channel.uploadVideo("Observer Design Pattern");

    return 0;
}