#include "cbuiltindlg.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CBuiltinDlg w;

    w.show();
    return QApplication::exec();
}
