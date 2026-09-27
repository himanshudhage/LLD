#include <iostream>
#include<vector>
#include<string>

using namespace std;

class Professor{
    public:
    string name;

    Professor(string name){
        this->name = name;
    }

    void display(){
        cout<<name<<endl;
    }
};

class Department{
    public:
     string dept_name;
     vector<Professor*>professor;

     Department(string dept_name , vector<Professor*>professor){
        this->dept_name = dept_name;
        this->professor = professor;
     }

     void show_professors(){
        cout<<"Department : "<<dept_name<<endl;

        for(int i = 0 ; i < professor.size();i++){
            cout<<professor[i]->name<<endl;
        }
     }

};

int main(){
    Professor*p1 = new Professor("Dr. smith");
    Professor*p2 = new Professor("Dr. joy");

    vector<Professor*>list;

    list.push_back(p1);
    list.push_back(p2);

    Department d("electronics engg" , list);

    d.show_professors();

    delete p1;
    delete p2;
}