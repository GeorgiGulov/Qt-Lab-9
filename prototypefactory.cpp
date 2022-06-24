//листинг "prototyoefactory.cpp"
#include "prototypefactory.h"
#include "record.h"
#include "EO.h"
#include "TO.h"
#include "SO.h"

Record *PrototypeFactory::createEO()
{
    static EO prototype;
    return prototype.clone();
}

Record *PrototypeFactory::createTO()
{
    static TO prototype;
    return prototype.clone();
}

Record *PrototypeFactory::createSO()
{
    static SO prototype;
    return prototype.clone();
}

