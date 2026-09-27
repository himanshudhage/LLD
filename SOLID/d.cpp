#include <iostream>
using namespace std;

class Database {
public:
    virtual void save() = 0;
};

class MySQL : public Database {
public:
    void save() override {
        cout << "Saving in MySQL\n";
    }
};

class UserService {
    Database* db;

public:
    UserService(Database* database) {
        db = database;
    }

    void saveUser() {
        db->save();
    }
};

int main() {
    MySQL mysql;

    UserService service(&mysql);
    service.saveUser();
}

// UserService does not care whether the database is MySQL, MongoDB, or something else.