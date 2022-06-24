//листинг "record.h"
#ifndef RECORD_H
#define RECORD_H
#include "QString"

class Record {
public:
    enum records{EO, TO, SO };

    virtual Record *clone()=0;


    virtual QString gettext2()=0;
    virtual void settext2(QString)=0;

    virtual QString gettextl()=0;
    virtual void settextl(QString)=0;

    virtual QString gettext()=0;
    virtual void settext(QString)=0;


    virtual ~Record(){}
    void set(QString, QString, QString, QString);
    QString getName();
    QString getAuto();
    QString getData();
    QString getPlace();
    records getType();

protected:
    QString nameKlient;
    QString modelAuto;
    QString placeTO;
    QString dataTO;
    records type;
};

#endif // RECORD_H
