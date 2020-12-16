#include <QApplication>
#include "mainwindow.h"
#include "jkqtplotter.h"
#include <QDir>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    JKQtBasePlotter::setDefaultJKQtBasePrinterUserSettings(QDir(app.applicationDirPath()).absoluteFilePath(FILENAME_SETTINGS), "plottersettings/");



    MainWindow* mainWid=new MainWindow(NULL);
    mainWid->show();

    return app.exec();
}


