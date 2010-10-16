#ifndef FTP_WINDOW_H
#define FTP_WINDOW_H
#include <QMainWindow>
#include <QObject>
#include <QPushButton>

class FtpWindow : public QMainWindow{
    Q_OBJECT

public:
    FtpWindow(QWidget* parent=0){
        ok = new QPushButton("OK",parent);
    }

private:
  QPushButton *ok;

};

//FtpWindow::FtpWindow(QWidget *p){



#endif // FTP_WINDOW_H
