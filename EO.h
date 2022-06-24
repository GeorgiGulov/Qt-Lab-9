//листинг "EO.h"
#ifndef EO_H
#define EO_H
#include "record.h"

class EO:public Record
{
    friend class PrototypeFactory;
public:
    Record* clone();
    QString gettextl();
    void settextl(QString);
private:
    EO();
    QString textl;

    QString gettext(){return 0;};
    void settext(QString){};

    QString gettext2(){return 0;}
    void settext2(QString){};
};

#endif // EO_H
