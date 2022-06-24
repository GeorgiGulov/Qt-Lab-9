//листинг "database.cpp"
#include "database.h"
#include "EO.h"
#include "prototypefactory.h"
Database* Database::post = 0;

Database* Database::getpost() {
    if(post == nullptr){
        post = new Database();
    }
    return post;
}

//проверка на непустой список
bool Database::hasDatabase() {
    if(list.empty())
            return false;
        else
            return true;
}

Database::Database() {
}

Database::~Database() {
    qDeleteAll(list);
}
