#include "mainwindow.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QApplication>
#include "DialogReconstructMarkerRecords.h"
#include<QDebug>
#include<QFileDialog>

static QPointer<QtLogFile> logFile=NULL;

void myMessageOutput(QtMsgType type, const char *msg)
{
    switch (type) {
    case QtDebugMsg:
        logFile->log_text_linebreak(QString(msg));
//        logFile->log_text("Debug",QString(msg));
        break;
    case QtWarningMsg:
        logFile->log_warning("Warning",QString(msg));
//        fprintf(stderr, "Warning: %s\n", msg);
        break;
    case QtCriticalMsg:
        logFile->log_error("Critical",QString(msg));
//        fprintf(stderr, "Critical: %s\n", msg);
        break;
    case QtFatalMsg:
        logFile->log_error("Fatal",QString(msg));
//        fprintf(stderr, "Fatal: %s\n", msg);
        abort();
    }

}


MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    ad=new AlexData;
    fd=new FCSdata;

    setMinimumSize(700,700);
    loadSettings();
    createWidgets();
    loadWidgetsSettings();
    connect(pushButtonBatch,SIGNAL(clicked()),this,SLOT(on_pushButtonBatch_clicked()));

//    ad->init(); // overwrites the last settings
    //    qDebug()<<ad->printParamsBurstSearch();
}



void MainWindow::on_mainTabs_currentChanged(int index)
{
    qDebug()<<"on_mainTabs_currentChanged "<<index;
    switch(index) {
    case 0:
//        widPhotons;
//        widBurstSearch;
        fd->clearMarker(); // FIXME if a new file is loaded, the marker ACF must be cleared
        break;
    case 1:
        widBurstView->refresh();
        break;
    case 2:
        widBurstStatisticsView->evaluate();
        break;
    case 3:
//        widAlex->evaluate();
        break;
    case 4:
        widFCS->plotAlex();
        break;
    }

}

void MainWindow::on_pushButtonBatch_clicked()
{
    AlexEvalLog::text("batch mode");
    logWidget->clearLogStore();
    QStringList files = QFileDialog::getOpenFileNames(this,"choose files for batch processing",ad->currentDir,"TTTR (*.t3r);;All (*.*)"); //"TTTR (*.t3r);;All (*.*)"
    if(files.isEmpty()) {AlexEvalLog::text("no files selected");return;}
//    if(ad->iniFilename.isEmpty()) {
//        AlexEvalLog::text("loadIni: ini filename=" + ad->iniFilename);
//        if(ad->init()) {
//            AlexEvalLog::warning("Error reading ini file "+ad->iniFilename);
//            ad->iniFilename="";
//            ad->init();
//        }
//    } else {
//        // FIXME do something
//    }
    logWidget->open_logfile(ad->currentDir+"/"+FILENAME_LOGFILE,true);

    for(QList<QString>::const_iterator file = files.begin();file!=files.end();++file) {
        widPhotons->automatedRun(*file);
        widBurstSearch->automatedRun();
        widAlex->automatedRun();
    }
    // save log file

    logWidget->close_logfile();
}

void MainWindow::intLogError(const QString &message)
{
    logWidget->log_error_linebreak(message);
}

void MainWindow::intLogWarning(const QString &message)
{
    logWidget->log_warning_linebreak(message);
}

void MainWindow::intLogText(const QString &message)
{
    logWidget->log_text_linebreak(message);
}



void MainWindow::createWidgets()
{
    qDebug("creating widgets...");
    QVBoxLayout *lay = new QVBoxLayout(this);
    setLayout(lay);
    splitLog=new QSplitter(this);
    splitLog->setOrientation(Qt::Vertical);
    lay->addWidget(splitLog);
    mainTabs=new QTabWidget(this);
    splitLog->addWidget(mainTabs);
    logWidget=new QtLogFile(this);
    logFile=logWidget;
    //qInstallMsgHandler(myMessageOutput);
    splitLog->addWidget(logWidget);

    qDebug("creating PhotonsWidget...");
    widPhotons=new PhotonsWidget(this,ad);
    qDebug("creating BurstSearchWidget...");
    widBurstSearch=new BurstSearchWidget(this,ad);
    QVBoxLayout* layPhotonsAndBurstSearch=new QVBoxLayout(this);

    layPhotonsAndBurstSearch->addWidget(widPhotons,1);
    layPhotonsAndBurstSearch->addWidget(widBurstSearch,0);
    pushButtonBatch= new QPushButton("&Batch Evaluation",this);
    layPhotonsAndBurstSearch->addWidget(pushButtonBatch);

    QWidget* widPhotonsAndBurstSearch=new QWidget(this);
    widPhotonsAndBurstSearch->setLayout(layPhotonsAndBurstSearch);
    mainTabs->addTab(widPhotonsAndBurstSearch, tr("Import and Burst Search"));


    qDebug("creating BurstView...");
    widBurstView=new BurstView(this,ad);
    mainTabs->addTab(widBurstView, tr("Burst View"));

    qDebug("creating BurstStatisticsView...");
    widBurstStatisticsView=new BurstStatisticsView(this,ad);
    mainTabs->addTab(widBurstStatisticsView, tr("Burst Statistics"));

    qDebug("creating ALEXHistogramsWidget...");
    widAlex=new ALEXHistogramsWidget(this,ad);
    mainTabs->addTab(widAlex, tr("ALEX Histograms"));

    qDebug("creating FCSwidget...");
    widFCS=new FCSwidget(this,ad,fd);
    mainTabs->addTab(widFCS, tr("FCS"));

    connect(mainTabs,SIGNAL(currentChanged(int)),this,SLOT(on_mainTabs_currentChanged(int)));
    connect(widPhotons,SIGNAL(backgroundCalculated()),widAlex,SLOT(setBackground()));

}



void MainWindow::loadWidgetsSettings()
{
    QSettings settings(QApplication::applicationDirPath()+"/" FILENAME_SETTINGS,QSettings::IniFormat);

    widPhotons->loadSettings(settings, "photons_widget/");
    widBurstSearch->loadSettings(settings,"burstsearch_widget/");
    widAlex->loadSettings(settings,"alexhistograms_widget/");
    widBurstView->loadSettings(settings,"BurstView_widget/");
    widBurstStatisticsView->loadSettings(settings,"BurstStatisticsView_widget/");
    widFCS->loadSettings(settings,"FCS_widget/");
    logWidget->saveSettings(settings,"logFile_widget/");
}

void MainWindow::loadSettings()
{
    QSettings settings(QApplication::applicationDirPath()+"/" FILENAME_SETTINGS,QSettings::IniFormat);
    settings.beginGroup("mainwindow");
    ad->currentDir=settings.value("working_directory", ad->currentDir).toString();
    ad->iniFilename=settings.value("alex_ini", ad->iniFilename).toString();
    ad->TTTRfilename=settings.value("TTTRfilename", ad->TTTRfilename).toString();
    this->restoreGeometry(settings.value("geometry",this->geometry()).toByteArray());
//    splitLog->restoreState(settings.value("splitterGeometry").toByteArray());
    settings.endGroup();
}

void MainWindow::storeSettings()
{
    QSettings settings(QApplication::applicationDirPath()+"/" FILENAME_SETTINGS,QSettings::IniFormat);
    settings.beginGroup("mainwindow");
    settings.setValue("working_directory", ad->currentDir);
    settings.setValue("TTTRfilename", ad->TTTRfilename);
    settings.setValue("TTTRfilename", ad->TTTRfilename);
    settings.setValue("geometry",this->saveGeometry());
    settings.setValue("splitterGeometry",splitLog->saveState());
    settings.endGroup();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QSettings settings(QApplication::applicationDirPath()+"/" FILENAME_SETTINGS,QSettings::IniFormat);
    this->storeSettings();
    widPhotons->storeSettings(settings,"photons_widget/");
    widBurstSearch->storeSettings(settings,"burstsearch_widget/");
    widAlex->storeSettings(settings,"alexhistograms_widget/");
    widBurstView->storeSettings(settings,"BurstView_widget/");
    widBurstStatisticsView->storeSettings(settings,"BurstStatisticsView_widget/");
    widFCS->storeSettings(settings,"FCS_widget/");
    logWidget->saveSettings(settings,"logFile_widget/");
}

