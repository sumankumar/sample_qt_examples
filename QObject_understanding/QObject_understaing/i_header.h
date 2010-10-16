#ifndef I_HEADER_H
#define I_HEADER_H


#include<QObject>
#include<QString>
#include<QDebug>

class VerboseObject : public QObject {

public:
    VerboseObject(QObject *parent, const QString& name):QObject(parent){
        parent->setObjectName(name);
        qDebug()<<"\n constructor \n";
    }
    ~VerboseObject() {
        qDebug()<<"\n Deleted"<<(*this).objectName()<<"\n";
    }
    void do_sthing() {
        qDebug()<<"\n do sthing"<<(*this).objectName()<<"\n";
    }


};
#endif // I_HEADER_H
