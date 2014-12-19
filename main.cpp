#include "mainwindow.h"
#include <QApplication>
#include "dialog.h"
#include "qglobalshortcut.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
   // w.setWindowFlags( );

    QGlobalShortcut gs;
    gs.setKey(QKeySequence("Alt+Ctrl+Space"));

    QObject::connect(&gs, SIGNAL(activated()),&w, SLOT(show()));


    w.show();



    return a.exec();
}
