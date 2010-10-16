#ifndef WINDOW_H
#define WINDOW_H
#include <QMainWindow>
#include <QObject>
#include <QToolBar>
#include <QLabel>
#include <QAction>
#include <QDebug>
#include <QPushButton>

class window : public QMainWindow
{
    Q_OBJECT
private:
    QToolBar * toolbar;
    QLabel *tool_label;
    QAction *settingsAct;
    QPushButton *ok;
public:
    window(QObject * parent=0);
public slots :


};

#endif // WINDOW_H
