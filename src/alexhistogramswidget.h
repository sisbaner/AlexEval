#ifndef ALEXHISTOGRAMSWIDGET_H
#define ALEXHISTOGRAMSWIDGET_H

#include <QWidget>
#include"alexdata.h"
#include"jkqtplotter.h"
#include "../DialogGMMparams.h"

#define FILENAME_ALEXDATA "AlexData.asc"
#define FILENAME_BURSTDONOR "BurstsD.asc"
#define FILENAME_BURSTACCEPTOR "BurstsA.asc"
#define FILENAME_INI "EvalParameters.ini"
#define FILE_EXTENSION_PLOT ".png"


namespace Ui {
class ALEXHistogramsWidget;
}

class ALEXHistogramsWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit ALEXHistogramsWidget(QWidget *parent = 0, AlexData* data=NULL);
    ~ALEXHistogramsWidget();

    /// store the settings of this widget in \a settings with prefix \a prefix (e.g. group)
    void storeSettings(QSettings& settings, const QString& prefix=QString("")) const;
    /// load the widget's settings from \a settings. the \a prefix must be the same as for storeSettings
    void loadSettings(QSettings& settings, const QString& prefix=QString(""));
    /// performs FRET analysis
    void evaluate();

    void automatedRun();

//    void importBackground();
private:
    Ui::ALEXHistogramsWidget *ui;
    AlexData* ad;
    DialogGMMparams* dlgGMM;
    JKQtPlotter* plot;
    QPointer<JKQTPgeoRectangle> pltSelectionRect;
    QAction* actZoomRange;
    GMMfitModel model; ///< current fitted model
    /// save the FRET parameters from user settings (spin boxes etc.) in the AlexData object.
    void getFRETparameters();

    Range_t plotRangeContour;
    size_t vRangeGraphTgTr;

    QList<double> contourLevels;
    bool relativeLevels;

    /// writes basic statistics to an info widget
    void writeStatistics();

    void plotDensity();
    void plotTgTr();
    void plotContour();
    void plotHistogramPR();
    void plotHistogramS();

    void fitGMM(GMMfit* gmm);


private slots:
    void on_pushButtonEval_clicked();

    /// make ALEX plots: scatter plot, density plot and proximity ratio histogram
    void drawPlots();

    /// save all evaluation data in the folder containing the .t3r file
    /// saves bursts of both channels,
    /// dual bursts with proximity and stoichiometry ratios,
    /// dual bursts from the selected subpopulation only and
    /// all evaluation parameters.
    void save();

    /// the ranges for the subpopulation selection FIXME: not used
    void selectRange(double xmin,double xmax,double ymin,double ymax);
    /// as selectRange, but with a different set of rectangle parameters
    void selectRangeRect(double x, double y, double width, double height);

    void setPlotRange(const Range_t &range, JKQtPlotter * plotter);

    void on_chkSelect_toggled(bool checked);
    void on_comboBoxPalette_currentIndexChanged();

    void zoomFull2DHistogram();
    void setBackground();
    void on_pushButtonLevels_clicked();
    void on_pushButtonGMM_clicked();
    void on_pushButtonGMMreset_clicked();
    void on_pushButtonEdit_clicked();

    void on_comboBoxPlot_currentIndexChanged();
protected:
//    virtual void focusInEvent( QFocusEvent * event);
};

#endif // ALEXHISTOGRAMSWIDGET_H
