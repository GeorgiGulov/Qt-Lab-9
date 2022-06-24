//листинг "SO.cpp"
#include "SO.h"

Record *SO::clone() {
    return new SO(*this);
}

QString SO::gettext() {
    return this->text;
}

void SO::settext(QString str) {
    this->text=str;
}

SO::SO() {
    type = Record::records::SO;
}

