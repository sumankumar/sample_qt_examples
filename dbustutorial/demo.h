#ifndef DEMO_H
#define DEMO_H
#include "src/demoifadaptor.h"
#include <gst/gst.h>


class MyDemo : public QObject
{
Q_OBJECT
public:
    explicit MyDemo(QObject *parent = 0);

public Q_SLOTS:
    QString SayBye();
    void SayHello(const QString &name, const QVariantMap &customdata);
    //gboolean bus_call(GstBus *bus,GstMessage *msg,gpointer data);
    void quitEventLoop();
Q_SIGNALS:
    void LateEvent(const QString &eventkind);

private:
    QEventLoop *loopptr;

};
#endif // DEMO_H
