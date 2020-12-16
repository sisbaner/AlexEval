#ifndef PHOTONSWIDGET_H
#define PHOTONSWIDGET_H

#include <QWidget>
#include "jkstyledbutton.h"
#include"parameters.h"
#include "jkqtplotter.h"
#include "alexdata.h"
#include "DialogReconstructMarkerRecords.h"

namespace Ui {
class PhotonsWidget;
}

class PhotonsWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit PhotonsWidget(QWidget *parent = 0, AlexData* data=NULL);
    ~PhotonsWidget();

    /// store the settings of this widget in \a settings with prefix \a prefix (e.g. group)
    void storeSettings(QSettings& settings, const QString& prefix=QString("")) const;
    /// load the widget's settings from \a settings. the \a prefix must be the same as for storeSettings
    void loadSettings(QSettings& settings, const QString& prefix=QString(""));

    void automatedRun(const QString &filename);

private:
    Ui::PhotonsWidget *ui;
    JKStyledButton* edt;

    AlexData* ad;

    ReconstructionMethod method;

    JKQtPlotter* plot;
    enum ChannelMappings {
        Donor=0,
        Acceptor=1
    } Route0, Pin4;

    double binwidth;

    double periodReconstruct;
    double offsetReconstruct;

private slots:
    void readT3Rfile(const QString file=QString(""));
    void plotIntensity();
    void getRangeStart(double startTime);
    void getRangeStop(double endTime);
    void backgroundAnalysis();
    void updateInfo(bool hasMarker);

    void sliderMoved(int value);

signals:
    void backgroundCalculated();

};

#endif // PHOTONSWIDGET_H
