#ifndef DIALOGRECONSTRUCTMARKERRECORDS_H
#define DIALOGRECONSTRUCTMARKERRECORDS_H

#include <QDialog>

namespace Ui {
class DialogReconstructMarkerRecords;
}

enum ReconstructionMethod {
    ReconstructFromDonor,
    ReconstructFromAcceptor,
    FullConstruction,
    SingleWavelengthFRET
};

/**
 * @brief The DialogReconstructMarkerRecords class
 *The user can choose between two methods: reconstruction from a single marker channel with an offset
 * or full construction. For the first case, the period for checkMarker may be supplied manually.
 * usage: you can use setPeriod, setStartTime, setOffset to set new preset values.
 * You should use setInfoText to set the number of marker events
 * (otherwise false information will be displayed)
 * After calling exec(), you can acquire the user settings via the getter methods.
 */
class DialogReconstructMarkerRecords : public QDialog
{
    Q_OBJECT

public:
    explicit DialogReconstructMarkerRecords(QWidget *parent = 0);
    ~DialogReconstructMarkerRecords();

    double getPeriod(); // in seconds
    void setPeriod(double period);
    double getOffset();
    void setOffset(double offset);
    ReconstructionMethod getChannel();
    void setChannel( ReconstructionMethod channel );
    void setInfoText(int nEventsD, int nEventsA, QString additionalInfo=QString(""));

    double getFullDonorPeriod();
    double getFullStartTime();
    void setFullStartTime(double startTime);
    double getFullOffset();

private slots:
    void on_radioButtonReconstruct_toggled(bool checked);
    void on_radioButtonFullConstruct_toggled(bool checked);
    void on_radioButtonFRET_toggled(bool checked);

    void setLabelTextChannel(QString channel);
    bool checkPossibleReconstruction();

private:
    Ui::DialogReconstructMarkerRecords *ui;
    int nMarkerEventsD;
    int nMarkerEventsA;

};

#endif // DIALOGRECONSTRUCTMARKERRECORDS_H
