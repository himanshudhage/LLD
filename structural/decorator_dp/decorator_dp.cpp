#include <iostream>
#include <string>
using namespace std;


// =====================
// Component
// =====================

class Coffee
{
public:

    virtual string get_description() = 0;

    virtual int get_cost() = 0;

    virtual ~Coffee() {}
};


// =====================
// Concrete Component
// =====================

class SimpleCoffee : public Coffee
{
public:

    string get_description() override
    {
        return "Simple Coffee";
    }

    int get_cost() override
    {
        return 50;
    }
};


// =====================
// Base Decorator
// =====================

class CoffeeDecorator : public Coffee
{
protected:

    Coffee *coffee;

public:

    CoffeeDecorator()
    {
        coffee = NULL;
    }

    virtual ~CoffeeDecorator()
    {
        delete coffee;
    }
};


// =====================
// Milk Decorator
// =====================

class MilkDecorator : public CoffeeDecorator
{
public:

    MilkDecorator(Coffee *coffee)
    {
        this->coffee = coffee;
    }

    string get_description() override
    {
        return coffee->get_description() + ", Milk";
    }

    int get_cost() override
    {
        return coffee->get_cost() + 20;
    }
};


// =====================
// Sugar Decorator
// =====================

class SugarDecorator : public CoffeeDecorator
{
public:

    SugarDecorator(Coffee *coffee)
    {
        this->coffee = coffee;
    }

    string get_description() override
    {
        return coffee->get_description() + ", Sugar";
    }

    int get_cost() override
    {
        return coffee->get_cost() + 30;
    }
};


// =====================
// Main
// =====================

int main()
{
    Coffee *coffee = new SimpleCoffee();

    cout << coffee->get_description() << endl;
    cout << coffee->get_cost() << endl;


    coffee = new MilkDecorator(coffee);

    cout << coffee->get_description() << endl;
    cout << coffee->get_cost() << endl;


    coffee = new SugarDecorator(coffee);

    cout << coffee->get_description() << endl;
    cout << coffee->get_cost() << endl;


    delete coffee;

    return 0;
}