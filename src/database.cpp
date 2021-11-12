#include "database.h"


Database::Database()
{

}

Database::~Database(){
    database.removeDatabase("warehouse");
}
void Database::connect(){
    database = QSqlDatabase::addDatabase("QPSQL");
    database.setHostName("localhost");
    database.setUserName("bair");
    database.setPassword("");
    database.setDatabaseName("warehouse");
};

bool Database::open(){
    return database.open();
};

void Database::close(){
    QString connection;
    connection = database.connectionName();
    database.close();
    database = QSqlDatabase();
    database.removeDatabase(connection);
}
