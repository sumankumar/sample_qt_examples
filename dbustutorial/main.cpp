#include "demo.h"
#include <glib-object.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    g_type_init();
    gst_init(&argc,&argv);
    MyDemo* demo = new MyDemo;
    new DemoIfAdaptor(demo);

    QDBusConnection connection = QDBusConnection::sessionBus();
    bool ret = connection.registerService("com.nokia.Demo");
    ret = connection.registerObject("/", demo);
    ret = connection.registerObject("/SayHello",demo);
    return a.exec();
}
