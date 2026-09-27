#include<iostream>
using namespace std;

class Logger{
    private:

    Logger(){
        cout<<"Logger Created"<<endl;
    }


    public:

    // disable from copying logger object
    Logger(const Logger&) = delete;

    Logger& operator =(const Logger&) = delete;

    


};

