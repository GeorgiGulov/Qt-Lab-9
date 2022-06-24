//листинг "database.h"
#ifndef DATABASE_H
#define DATABASE_H

#include "record.h"
#include "QList"

class Database
{
public:
    static Database*  getpost();
    QList <Record*> list;   //список
    bool hasDatabase();
    ~Database();
private:
    static Database* post;
    Database();
};

#endif // DATABASE_H

