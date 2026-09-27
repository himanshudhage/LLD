/*
We use the Abstract Factory pattern when we need to create multiple related objects that should work together,
without tying our code to specific concrete classes.

The Application never creates MySQLConnection or PostgreSQLConnection directly. 
It simply asks the DatabaseFactory for a Connection and a Query. 
The selected concrete factory decides which specific objects to create. 
This is the essence of the Abstract Factory pattern.

                DatabaseFactory
                      |
        ----------------------------
        |                          |
   MySQLFactory             PostgreSQLFactory
        |                          |
   ----------------          ----------------
   |              |          |              |
MySQLConnection MySQLQuery PostgreSQLConnection PostgreSQLQuery

Each factory creates only its own family of objects.
*/


#include <iostream>
#include <memory>

using namespace std;

//=========================================================
// ABSTRACT PRODUCTS
// These are interfaces (contracts).
// Every database must provide its own Connection and Query.
//=========================================================

class Connection {
public:
    virtual void connect() = 0;      // Every database must implement connect()
    virtual ~Connection() {}
};

class Query {
public:
    virtual void execute() = 0;      // Every database must implement execute()
    virtual ~Query() {}
};

//=========================================================
// MYSQL PRODUCTS
// Concrete implementations for MySQL
//=========================================================

class MySQLConnection : public Connection {
public:
    void connect() override {
        cout << "Connected to MySQL Database\n";
    }
};

class MySQLQuery : public Query {
public:
    void execute() override {
        cout << "Executing MySQL Query\n";
    }
};

//=========================================================
// POSTGRESQL PRODUCTS
// Concrete implementations for PostgreSQL
//=========================================================

class PostgreSQLConnection : public Connection {
public:
    void connect() override {
        cout << "Connected to PostgreSQL Database\n";
    }
};

class PostgreSQLQuery : public Query {
public:
    void execute() override {
        cout << "Executing PostgreSQL Query\n";
    }
};

//=========================================================
// ABSTRACT FACTORY
//
// This is only a blueprint (interface).
// It says:
// "Every database factory must know how to create
//  a Connection and a Query."
//
// Notice:
// It DOES NOT say HOW to create them.
//=========================================================

class DatabaseFactory {
public:

    // Returns a Connection object.
    // The actual object could be:
    // - MySQLConnection
    // - PostgreSQLConnection
    virtual unique_ptr<Connection> createConnection() = 0;

    // Returns a Query object.
    // The actual object could be:
    // - MySQLQuery
    // - PostgreSQLQuery
    virtual unique_ptr<Query> createQuery() = 0;

    virtual ~DatabaseFactory() {}
};

//=========================================================
// MYSQL FACTORY
//
// Responsible for creating MySQL-related objects.
//=========================================================

class MySQLFactory : public DatabaseFactory {
public:

    unique_ptr<Connection> createConnection() override {

        cout << "[Factory] Creating MySQL Connection...\n";

        return make_unique<MySQLConnection>();
    }

    unique_ptr<Query> createQuery() override {

        cout << "[Factory] Creating MySQL Query...\n";

        return make_unique<MySQLQuery>();
    }
};

//=========================================================
// POSTGRESQL FACTORY
//
// Responsible for creating PostgreSQL-related objects.
//=========================================================

class PostgreSQLFactory : public DatabaseFactory {
public:

    unique_ptr<Connection> createConnection() override {

        cout << "[Factory] Creating PostgreSQL Connection...\n";

        return make_unique<PostgreSQLConnection>();
    }

    unique_ptr<Query> createQuery() override {

        cout << "[Factory] Creating PostgreSQL Query...\n";

        return make_unique<PostgreSQLQuery>();
    }
};

//=========================================================
// CLIENT
//
// The Application DOES NOT know:
//
// MySQLConnection
// PostgreSQLConnection
// MySQLQuery
// PostgreSQLQuery
//
// It only knows:
//
// Connection
// Query
// DatabaseFactory
//
// That's the whole point of Abstract Factory.
//=========================================================

class Application {

private:

    unique_ptr<Connection> connection;
    unique_ptr<Query> query;

public:

    // Constructor receives ANY DatabaseFactory.
    // It could be MySQLFactory or PostgreSQLFactory.
    Application(DatabaseFactory& factory) {

        cout << "\nApplication requesting objects from Factory...\n\n";

        // Ask the factory for a Connection.
        // Application doesn't know which concrete class it gets.
        connection = factory.createConnection();

        // Ask the factory for a Query.
        query = factory.createQuery();
    }

    void run() {

        cout << "\nRunning Application...\n\n";

        connection->connect();
        query->execute();
    }
};

//=========================================================
// MAIN
//=========================================================

int main() {

    // Pointer to the abstract factory.
    // At runtime it can point to:
    // - MySQLFactory
    // - PostgreSQLFactory
    unique_ptr<DatabaseFactory> factory;

    int choice;

    cout << "Select Database\n";
    cout << "1. MySQL\n";
    cout << "2. PostgreSQL\n";
    cout << "Enter Choice : ";

    cin >> choice;

    // Decide which factory to create.
    if (choice == 1) {

        cout << "\nCreating MySQL Factory...\n";

        factory = make_unique<MySQLFactory>();
    }
    else {

        cout << "\nCreating PostgreSQL Factory...\n";

        factory = make_unique<PostgreSQLFactory>();
    }

    // Pass the selected factory to the Application.
    // The Application doesn't know which factory it received.
    Application app(*factory);

    // Start the application.
    app.run();

    return 0;
}