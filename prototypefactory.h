//листинг "prototypefactory.h"
#ifndef PROTOTYPEFACTORY_H
#define PROTOTYPEFACTORY_H

#include "record.h"
#include "EO.h"
#include "TO.h"
#include "SO.h"

class PrototypeFactory
{
public:
    Record* createEO();       //создание EO
    Record* createTO();       //создание TO
    Record* createSO();       //создание SO

};

#endif // PROTOTYPEFACTORY_H
