#ifndef FCSCURVE_H
#define FCSCURVE_H

#include <QVector>
#include <QString>
#include "parameters.h"

class FCScurve : public QVector<double>
{
    QString name;
    int numberOfPhotonsUsed;
    const FCSparams_t* FCSparams;
public:
    FCScurve();
    FCScurve(QString name, FCSparams_t* params=NULL);

    GetSetMacro(QString, name);
    GetSetMacro(int, numberOfPhotonsUsed);
    const FCSparams_t* getFCSparams() const {return FCSparams;}
    void set_FCSparams(const FCSparams_t& params) {FCSparams=&params;}
    void set_FCSparams(const FCSparams_t* params) {FCSparams=params;}

};

#endif // FCSCURVE_H
