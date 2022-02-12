#include "SwiftEditor.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SwiftEditor w;
    w.show();
    return a.exec();
}
