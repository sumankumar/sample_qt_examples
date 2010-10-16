#include <QDebug>
#include "mc.h"
#include "mydata.h"
#include <QTimer>

Window::Window(QObject* parent){

    QMainWindow::setFixedHeight(400);
    QMainWindow::setFixedWidth(800);

    ok = new QPushButton("OK",this);
    QObject::connect(ok,SIGNAL(clicked()),this,SLOT(start_machine_cycle()) );

    data = new MyData("sum",this);
    QObject::connect(data,SIGNAL(send(QString)),this,SLOT(send_emitted()));
}

void Window::start_machine_cycle(){

    qDebug() <<"Start MC started  ";

    mc = new QStateMachine(this);
    mc->setObjectName("base_machine_cycle");

#if 0
    s1= new MyState(data,this);
    s1->setObjectName("s1_state");
    mc->addState(s1);

    s2= new MyState(data,this);
    s2->setObjectName("s2_state");
    mc->addState(s2);

    final_s4 = new QFinalState();
    final_s4->setObjectName("final_state");
    mc->addState(final_s4);

    s1->addTransition(data,SIGNAL(send(QString)),s2);
    s2->addTransition(data,SIGNAL(send(QString)),final_s4);

       mc->setInitialState(s1);

#endif

    MyState *waitForUutState  = new MyState(data,this);
    waitForUutState->setObjectName("waitForUutStateObject");
    mc->addState(waitForUutState);

    MyState *identifyDeviceState = new MyState(data,this);
    identifyDeviceState->setObjectName("identifyDeviceStateObject");
    mc->addState(identifyDeviceState);

    MyState *swUpdateState = new MyState(data,this);
    swUpdateState->setObjectName("swUpdateStateObject");
    mc->addState(swUpdateState);

    MyState *selfTestState =  new MyState(data,this);
    selfTestState->setObjectName("selfTestStateObject");
    mc->addState(selfTestState);

    MyState *variantVerificationState = new MyState(data,this);
    variantVerificationState->setObjectName("variantVerificationStateObject");
    mc->addState(variantVerificationState);

    MyState *typeLabelPrintingState = new MyState(data,this);
    typeLabelPrintingState->setObjectName("typeLabelPrintingStateObject");
    mc->addState(typeLabelPrintingState);

    MyState *reportResultState = new MyState(data,this);
    reportResultState->setObjectName("reportResultStateObject");
    mc->addState(reportResultState);

    MyState *releaseUutState = new MyState(data,this);
    releaseUutState->setObjectName("releaseUutStateObject");
    mc->addState(releaseUutState);

    mc->setInitialState(waitForUutState);

    /*waitForUutState transitions */
    waitForUutState->addTransition(data,SIGNAL(uutDetectedSucess(MyData*)),identifyDeviceState);
    waitForUutState->addTransition(data,SIGNAL(uutDetectedFail(MyData*)),waitForUutState);

    identifyDeviceState->addTransition(data,SIGNAL(identifyDeviceOk()),swUpdateState);
    identifyDeviceState->addTransition(data,SIGNAL(identifyDeviceNotOk()),reportResultState);

    swUpdateState->addTransition(data,SIGNAL(swUpdateOk()),selfTestState);
    swUpdateState->addTransition(data,SIGNAL(swUpdateNotOk()),reportResultState);

    selfTestState->addTransition(data,SIGNAL(selfTestOk()),variantVerificationState);
    selfTestState->addTransition(data,SIGNAL(selfTestNotOk()),reportResultState);

    variantVerificationState->addTransition(data,SIGNAL(variantVerificationOk()),typeLabelPrintingState);
    variantVerificationState->addTransition(data,SIGNAL(variantVerificationNotOk()),reportResultState);

    typeLabelPrintingState->addTransition(data,SIGNAL(typeLabelPrintingOk()),reportResultState);

    reportResultState->addTransition(data,SIGNAL(reportResultOk()),releaseUutState);

    releaseUutState->addTransition(data,SIGNAL(releaseUutOk()),waitForUutState);


#if 0

    s1= new QState();
    s1->setObjectName("s1_state");
    mc->addState(s1);

    s2 = new QState();
    s2->setObjectName("s2_state");
    mc->addState(s2);

    s3 = new QState();
    s3->setObjectName("s3_state");
    mc->addState(s3);

    s4 = new QState();
    s4->setObjectName("s4_state");
    mc->addState(s4);

    final_s4 = new QFinalState();
#endif






    QObject::connect(mc,SIGNAL(started()),this,SLOT(mc_started()));
    QObject::connect(mc,SIGNAL(stopped()),this,SLOT(mc_stopped()));
    QObject::connect(mc,SIGNAL(finished()),this,SLOT(mc_finished()));
    QObject::connect(mc,SIGNAL(entered()),this,SLOT(mc_entered()));
    QObject::connect(mc,SIGNAL(exited()),this,SLOT(mc_exited()));


#if 0
    s1->addTransition(data,SIGNAL(send(QString)),s2);
    s2->addTransition(data,SIGNAL(send(QString)),s3);
    s3->addTransition(data,SIGNAL(send(QString)),final_s4);
#endif

    mc->start();

     qDebug() <<"Start MC Ended  ";
}

void Window::mc_started(){

    qDebug()<<"slot for statemachine started signal ";
    //QTimer *timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this, SLOT(timeout_completed()));
    //timer->start(1000);
   // QTimer::singleShot(6000, this, SLOT(timeout_completed()));
    //data->doSend("start");
}

void Window::mc_stopped(){

    qDebug()<<"slot for statemachine stopped signal ";
}

void Window::mc_finished(){

    qDebug()<<"slot for statemachine finished signal: "<< this->objectName();
}

void Window::mc_entered(){

    qDebug()<<"slot for statemachine entered signal: "<< this->objectName();
}

void Window::mc_exited(){

    qDebug()<<"slot for statemachine exited signal: "<< this->objectName();
}

void MyState::onEntry(QEvent *event){

    qDebug()<< "on entry ";


    MyData::machineState choice = m_data->getProcessState();

    switch(choice){
    case UUT_DETECTED_STATE:{

            m_data->setProcessState(UUT_DETECTED_STATE);
            /*
            UUT_DETECTION FUNCTIONALITY()
            {
                //intiate UUT detection state
                //if any error , "emit uutDetectedFail()" signal
                //on success , "emit uutDetectedSucess()" signal
            }
            */


            break;
        }
    case IDENTIFY_DEVICE_STATE:{

            break;
        }
    case SW_UPDATE_STATE:{

            break;
        }
    case SELF_TEST_STATE:{

            break;
        }
    case VARIANT_VERIFICATION_STATE:{

            break;
        }
    case TYPELABEL_PRINTING_STATE:{

            break;
        }
    case REPORT_RESULT_STATE:{

            break;
        }

    case RELEASE_UUT_STATE:{

            break;
        }
    default:{
        qDebug()<<"UNDEFINED_STATE";
    }


}


