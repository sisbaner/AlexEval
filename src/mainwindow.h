#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QTableWidget>
#include "photonswidget.h"
#include "burstsearchwidget.h"
#include "alexhistogramswidget.h"
#include "BurstStatisticsView.h"
#include "BurstView.h"
#include "alexdata.h"
#include <QSettings>
#include "logfile.h"
#include "qtlogfile.h"
#include <QSplitter>
#include "alexevallog.h"
#include "FCSwidget.h"
#include <QPushButton>

#define FILENAME_SETTINGS "alexeval.ini"
#define FILENAME_LOGFILE "alexeval.log"


void myMessageOutput(QtMsgType type, const char *msg);

class MainWindow : public QWidget, public AlexEvalLog {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

friend class PhotonsWidget;
friend class BurstSearchWidget;
friend class BurstStatisticsView;
friend class BurstView;
friend class ALEXHistogramsWidget;
friend class FCSwidget;
friend class QtLogFile;



signals:

public slots:
    void on_mainTabs_currentChanged(int index);
    void on_pushButtonBatch_clicked();

protected:
    /// handling for the log widget
    void intLogError(const QString& message);
    void intLogWarning(const QString& message);
    void intLogText(const QString& message);


    /// creates the friend widgets in tabs
    void createWidgets();
    PhotonsWidget* widPhotons;
    BurstSearchWidget* widBurstSearch;
    BurstStatisticsView* widBurstStatisticsView;
    BurstView* widBurstView;
    ALEXHistogramsWidget* widAlex;
    FCSwidget* widFCS;
    QTabWidget* mainTabs;
    QtLogFile* logWidget;
    QSplitter* splitLog;
    QPushButton* pushButtonBatch;

    /// the data class instance which is shared by all widgets
    AlexData* ad;
    FCSdata* fd;

    /// calls the loadSettings methods of all widgets
    void loadWidgetsSettings();
    /// load the last user settings for the main window from ini file
    void loadSettings();
    /// saves the user settings from ini file
    void storeSettings();

    /// called when the application is closed. It will call the storeSettings() functions of all widgets
    virtual void closeEvent(QCloseEvent* event);

};


#endif // MAINWINDOW_H
