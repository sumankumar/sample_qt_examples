#include<window.h>
#include <QFile>

window::window(QObject *parent )
{
    QMainWindow::setFixedHeight(400);
    QMainWindow::setFixedWidth(800);

    QWidget * central_widget = new QWidget(this,Qt::Widget);


        //central_widget->setMinimumSize ( 400, 300 );
        toolbar = new QToolBar("suman",this);
        toolbar->setFloatable(FALSE);
        tool_label = new QLabel("tool_label1",toolbar,Qt::Widget);
        toolbar->addWidget(tool_label);
        toolbar->setFixedHeight(50);
        toolbar->setFixedWidth(300);

        //ok = new QPushButton("OK",this);

        if(QFile("settings.png").exists()){
        settingsAct = new QAction(QIcon("./settings.png"), tr("&Settings"), this);
        settingsAct->setStatusTip(tr("environment settings"));
        toolbar->addAction(settingsAct);
    }
        else
        qDebug() << "File doesnt exists\n";
}
