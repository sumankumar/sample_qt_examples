#include<QApplication>
#include "mc.h"

int main(int argc, char * argv[]){

    QApplication app(argc,argv);
    Window w(&app);

    w.show();
    app.exec();
    return 0;
}
