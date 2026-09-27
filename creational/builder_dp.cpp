// Builder Design Pattern means creating an object step-by-step using a separate builder class.

#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
    string color;
    string engine;
    bool sunroof;

    void disply()
    {
        cout << "Color: " << color << endl;
        cout << "Engine: " << engine << endl;
        cout << "Sunroof: " << (sunroof ? "Yes" : "No") << endl;
    }
};

class CarBuilder
{
private:
    Car car;

public:
    CarBuilder &setColor(string color)
    {
        car.color = color;
        return *this;
    }

    CarBuilder &setEngine(string engine)
    {
        car.engine = engine;
        return *this;
    }

    CarBuilder &setSunroof(bool value)
    {
        car.sunroof = value;
        return *this;
    }

    Car build()
    {
        return car;
    }
};

int main()
{
    Car car = CarBuilder()
                  .setColor("Black")
                  .setEngine("Petrol")
                  .setSunroof(true)
                  .build();

    car.disply();

    //     CarBuilder builder;
    // builder.setColor("Black");
    // builder.setEngine("Petrol");
    // builder.setSunroof(true);

    // Car car = builder.build();

    // car.display();
}