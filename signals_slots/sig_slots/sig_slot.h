#ifndef SIG_SLOT_H
#define SIG_SLOT_H
#include <QObject>
#include <QDebug>

class sender :public QObject
{
    Q_OBJECT
signals:
    void send(int a);
public:
    void do_stuff(int b);

};

class receiver:public QObject
{
    Q_OBJECT
public slots:
    void get(int a ){
        qDebug()<<"received :"<<a;
    }
};

void sender::do_stuff(int b)
{
    emit send(b);
}
#endif // SIG_SLOT_H
