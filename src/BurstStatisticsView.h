#ifndef BURSTSTATISTICSVIEW_H
#define BURSTSTATISTICSVIEW_H

#include <QWidget>
#include "alexdata.h"
#include "jkqtplotter.h"

namespace Ui {
class BurstStatisticsView;
}

class BurstStatisticsView : public QWidget
{
    Q_OBJECT
    
public:
    explicit BurstStatisticsView(QWidget *parent = 0, AlexData* data = NULL);
    ~BurstStatisticsView();

    /// store the settings of this widget in \a settings with prefix \a prefix (e.g. group)
    void storeSettings(QSettings& settings, const QString& prefix=QString("")) const;
    /// load the widget's settings from \a settings. the \a prefix must be the same as for storeSettings
    void loadSettings(QSettings& settings, const QString& prefix=QString(""));

    /// calculates burst statistics and plots burst duration distribution, burst size distribution and burst rate distribution
    void evaluate();
    

private:
    Ui::BurstStatisticsView *ui;
    AlexData* ad;
    FRETparams_t rangeTgTr;
    void plotStatistics();
    void plotTgTr();

private slots:
    void on_pushButtonRefresh_clicked();
    void on_spinBoxBins_editingFinished();
};

#endif // BURSTSTATISTICSVIEW_H
