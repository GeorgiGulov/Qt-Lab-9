//листинг "record.cpp"
#include "QString"
#include "record.h"

void Record::set(QString nameKlient, QString placeTO, QString modelAuto, QString dataTO) {
    this->nameKlient = nameKlient;
    this->modelAuto = modelAuto;
    this->placeTO = placeTO;
    this->dataTO = dataTO;
}

QString Record::getName() {
    return this->nameKlient;
}

QString Record::getAuto() {
    return this->modelAuto;
}

QString Record::getPlace() {
    return this->placeTO;
}

QString Record::getData() {
    return this->dataTO;
}

Record::records Record::getType() {
    return type;
}
