//листинг "TO.h"
#ifndef TO_H
#define TO_H
#include "record.h"

class TO:public Record
{
    friend class PrototypeFactory;
public:
    Record* clone();
    QString gettext2();
    void settext2(QString);
private:
    TO();
    QString text2;

    QString gettext(){return 0;};
    void settext(QString){};

    QString gettextl(){return 0;};
    void settextl(QString){};
};
#endif // TO_H
