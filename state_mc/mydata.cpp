#include "mydata.h"
#include <QDebug>


void MyData::setStr(QString s1){

    str = s1;

}
const QString& MyData::getStr() const{

    return str;

}

void MyData::doSend(QString s3){
    emit send(s3);
}

void MyData::send_emitted(QString s3){
    qDebug()<<"send_emmitted: "<<s3;
}
void MyData::setProcessState(MyData::machineState state ){
    processState = state;
}

MyData::machineState MyData::getProcessState() const{
    return processState;
}
