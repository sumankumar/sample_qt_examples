#ifndef MAIN_CPP
#define MAIN_CPP


#include <QApplication>
#include "window.h"
int main(int argc ,char * argv[])
{
    QApplication a(argc,argv);
    window w(&a);
    w.show();
    a.exec();
    return 0;
}

#endif // MAIN_CPP
