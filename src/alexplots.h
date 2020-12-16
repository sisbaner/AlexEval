#ifndef ALEXPLOTS_H
#define ALEXPLOTS_H
#include<QVector>
#include<gsl/gsl_histogram.h>
#include<jkqtplotter.h>
#include "alexdata.h"


/// plots the histogram hist as a horizontal bar graph to plot
void plotHist(JKQtPlotter * plot, gsl_histogram * hist );

/**
 * @brief plotAlternation plot the number of photons in an alternation period averaged over the first 10000 excitation periods and displays the countrate
 * @param[out] plot A JKQtPlotter plotting widget
 * @param[in] ad the data structure containing the photon arrival times and the markers
 */
void plotAlternation(JKQtPlotter *plot, const AlexData* const ad);

/**
 * @brief plotDensity standard ALEX plot.
 * Each burst's proximity and stoichiometry ratios are plotted in a 2D map. Frequencies are color encoded.
 * @param[out] plot A JKQtPlotter plotting widget
 * @param[in] ad the data structure containing the dual bursts
 * @param[in] nbinsnumber of bins for the 2D histogram (PR and SR)
 */
void plotDensity(JKQtPlotter *plot, const AlexData* const ad, const int nbins = 100);


#include <QComboBox>
class QComboBoxChannel: public QComboBox
{
    Q_OBJECT
public:
    QComboBoxChannel(QWidget *parent=NULL);
    uint channel() const;

};


#endif // ALEXPLOTS_H
