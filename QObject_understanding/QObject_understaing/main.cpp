#include<QApplication>
#include "i_header.h"
int main(int argc , char* argv[])
{
    QApplication A(argc ,argv);

    VerboseObject top(&A,"Top");
#if 1
    VerboseObject *x = new VerboseObject(&top,"x");
    VerboseObject *y = new VerboseObject(&top,"y");
    VerboseObject *z = new VerboseObject(&top,"z");

    top.do_sthing();
    x->do_sthing();
    y->do_sthing();
    z->do_sthing();
#endif

    //A.exec();
    return 0;
}

