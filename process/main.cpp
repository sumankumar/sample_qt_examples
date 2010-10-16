#include <QApplication>
#include <QProcess>
#include "ftp_window.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    FtpWindow w;

    w.show();

    return 0;
};
