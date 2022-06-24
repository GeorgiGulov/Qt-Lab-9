//листинг "EO.cpp"
#include "EO.h"

Record *EO::clone() {
    return new EO(*this);
}

QString EO::gettextl() {
    return this->textl;
}

void EO::settextl(QString str) {
    this->textl=str;
}

EO::EO() {
    type = Record::records::EO;
}
