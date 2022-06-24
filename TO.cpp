//листинг "SO.cpp"
#include "TO.h"
#include "record.h"

Record *TO::clone() {
    return new TO(*this);
}

QString TO::gettext2() {
    return this->text2;
}

void TO::settext2(QString str) {
    this->text2=str;
}

TO::TO() {
    type = Record::records::TO;
}

