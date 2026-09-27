#include <iostream>
using namespace std;

class Logger {

private:

    // Private constructor
    // Nobody outside the class can create Logger objects directly
    Logger() {
        cout << "Logger Created\n";
    }


public:

    // Disable copying of Logger objects
    // Prevents: Logger b = a;
    Logger(const Logger&) = delete;

    // Disable assigning one Logger object to another
    // Prevents: b = a;
    Logger& operator=(const Logger&) = delete;


    // This function gives access to the single Logger object
    static Logger& getInstance() {

        // Object is created only once
        // Next time this function is called, the same object is returned
        static Logger instance;

        return instance;
    }


    // Function to print log messages
    void log(string message) {
        cout << message << endl;
    }
};


int main() {

    // First call:
    // Creates the Logger object
    Logger& logger1 = Logger::getInstance();


    // Second call:
    // Does NOT create a new object
    // Returns the same Logger object
    Logger& logger2 = Logger::getInstance();


    // Both use the same Logger object
    logger1.log("Hello");
    logger2.log("World");


    // Check whether both references point to the same object
    // Output: 1 (true)
    cout << (&logger1 == &logger2) << endl;


    return 0;
}