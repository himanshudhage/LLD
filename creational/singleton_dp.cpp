
//mayers singleton method 
#include<iostream>
using namespace std;

class Logger{
private:
Logger(){}

public:
    //copy constructor is deleted
    Logger(const Logger&) = delete;
    //assigment operator is deleted
    Logger&operator = (const Logger&) = delete;

    static Logger& get_instance(){
        static Logger logger;
        return logger;
    }

    void log(string message){
        cout<<"log : "<<message<<endl;
    }
};

int main(){
    Logger &logger1 = Logger::get_instance(); 
    Logger &logger2 = Logger::get_instance();

    logger1.log("program started");
    logger2.log("reading file");

    if(&logger1 == &logger2){
         cout<<"same logger instance"<<endl;
    }
}