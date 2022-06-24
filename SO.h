//листинг "SO.h"
#ifndef SO_H
#define SO_H

#include "record.h"

class SO:public Record
{
    friend class PrototypeFactory;
public:
    Record* clone();
    QString gettext();
    void settext(QString);
private:
    SO();
    QString text;

    QString gettextl(){return 0;};
    void settextl(QString){};

    QString gettext2(){return 0;};
    void settext2(QString){};
};

#endif // SO_H
