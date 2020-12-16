#ifndef BURSTSEARCHWIDGET_H
#define BURSTSEARCHWIDGET_H

#include <QWidget>
#include<QSettings>
#include "parameters.h"
#include "alexdata.h"
#include "jkstyledbutton.h"
#include"jkqtplotter.h"


namespace Ui {
class BurstSearchWidget;
}

class BurstSearchWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit BurstSearchWidget(QWidget *parent = 0, AlexData *data=NULL);
    ~BurstSearchWidget();
    
    /// store the settings of this widget in \a settings with prefix \a prefix (e.g. group)
    void storeSettings(QSettings& settings, const QString& prefix=QString("")) const;
    /// load the widget's settings from \a settings. the \a prefix must be the same as for storeSettings
    void loadSettings(QSettings& settings, const QString& prefix=QString(""));
    void automatedRun();

private:
    Ui::BurstSearchWidget *ui;
    AlexData* ad;
    JKStyledButton* edt;

    void getParameters();
    void setParameters();
//    JKQtPlotter* plot;

private slots:
    void setMethodSingle(int index);
    void setMethodDual(int index) {setMethod();}
    void setMethod();
    void setDisabledMethodLowerFrame(bool toggle);

    void on_pushButton_clicked();
    void on_pushButtonSaveIni_clicked();
    void on_pushButtonBurstView_clicked();

    void runBurstSearch();

    void loadIni();



};


#endif // BURSTSEARCHWIDGET_H
