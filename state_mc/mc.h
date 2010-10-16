#ifndef MC_H
#define MC_H

#include<QMainWindow>
#include<QPushButton>
#include<QStateMachine>
#include<QFinalState>
#include "mydata.h"
#include <QAbstractState>
#include <QDebug>
#if 1
class MyState :public QState
{
    Q_OBJECT

public :
    MyState(MyData* data,QObject* p)
        :m_data(data) {}

protected:

    void onExit(QEvent *event){
        qDebug()<< " on exit ";
    }

private:
    MyData*  m_data;
    QState s;
};
#endif

//class Window: public QMainWindow ,public QState {
class Window: public QMainWindow  {

    Q_OBJECT
public:
    Window(QObject* parent);

signals:


private slots:
    void start_machine_cycle();
    void mc_started();
    void mc_stopped();
    void mc_finished();
    void mc_entered();
    void mc_exited();





private:

    MyData* data;
    QPushButton *ok;
    QStateMachine *mc;

    MyState* s1;
    MyState* s2;

    QFinalState *final_s4;
#if 0

    QState *s1;
    QState *s2;
    QState *s3;
    QState *s4;
    QFinalState *final_s4;
#endif


};

#endif // MC_H
