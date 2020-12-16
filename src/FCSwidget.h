#ifndef FCSWIDGET_H
#define FCSWIDGET_H

#include <QWidget>
#include "FCSdata.h"
#include"jkqtplotter.h"

#define FILENAME_FCS "FCS.csv"
#define FILENAME_FCS_SUBPOPULATION "FCSselectedBursts.csv"


namespace Ui {
class FCSwidget;
}

class FCSwidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit FCSwidget(QWidget *parent = 0, AlexData *data=NULL,FCSdata* fd=NULL);
    ~FCSwidget();

    /// store the settings of this widget in \a settings with prefix \a prefix (e.g. group)
    void storeSettings(QSettings& settings, const QString& prefix=QString("")) const;
    /// load the widget's settings from \a settings. the \a prefix must be the same as for storeSettings
    void loadSettings(QSettings& settings, const QString& prefix=QString(""));

    void plotAlex();
private:
    Ui::FCSwidget *ui;
    FCSdata* fd;
    AlexData* ad;
    JKQtPlotter* plot;
    QPointer<JKQTPgeoRectangle> pltSelectionRect;
    QAction* actZoomRange;
    int nbins;

    double alphaSelectionRectangle;

private slots:
    void save() const;

    /// the ranges for the subpopulation selection
    void selectRangeRect(double x, double y, double width, double height);
    void setPlotRange(const Range_t &range, JKQtPlotter * plotter);

    void getParameters();

    /// performs selection of a subpopulation and auto- and crosscorrelation thereof
    void runFCS();
    void loadAndRunFCS();
    void plotFCS();
    void plotFCS1();
    void plotFCS2();


    void on_chkSelect_toggled(bool checked);
    void on_comboBoxPalette_currentIndexChanged();
    void on_pushButtonRefresh_clicked();
    void plotDensity();

    void spinBoxMinSetMax(int max);

};

#endif // FCSWIDGET_H
