#ifndef MAIN_CPP
#define MAIN_CPP
#include<QApplication>
#include "moc_sig_slot.cpp"


int main(int argc , char *argv[])
{
    QApplication app(argc,argv);
    sender A;
    receiver B;

    QObject ::connect(&A,SIGNAL(send(int)),&B,SLOT(get(int)));
    A.do_stuff(5);
    return 0;
}
#endif // MAIN_CPP
