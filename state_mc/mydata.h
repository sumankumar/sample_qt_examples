#ifndef MYDATA_H
#define MYDATA_H
#include <QObject>
#include <QString>


class MyData:public QObject {

    Q_OBJECT


public:
    enum machineState {
    UNDEFINED_STATE,
    UUT_DETECTED_STATE,
    IDENTIFY_DEVICE_STATE,
    SW_UPDATE_STATE,
    SELF_TEST_STATE,
    VARIANT_VERIFICATION_STATE,
    TYPELABEL_PRINTING_STATE,
    REPORT_RESULT_STATE,
    RELEASE_UUT_STATE

    };

    MyData(const QString &s,QObject* parent ):str(s){}

//    MyData(MyData &d1){
//        str= d1.str;
//    }

    void setStr(QString s1);
    const QString& getStr() const;

    void setProcessState(machineState );
    machineState getProcessState() const;

    void doSend(QString s3);

public slots:

    void send_emitted(QString );

signals:
    void send(QString );

    void uutDetectedSucess();
    void uutDetectedFail();
    void identifyDeviceOk();
    void identifyDeviceNotOk();
    void swUpdateOk();
    void swUpdateNotOk();
    void selfTestOk();
    void selfTestNotOk();
    void variantVerificationOk();
    void variantVerificationNotOk();
    void typeLabelPrintingOk();
    void reportResultOk();
    void releaseUutOk();

private:
    QString str;

    machineState processState;


};

#endif // MYDATA_H
