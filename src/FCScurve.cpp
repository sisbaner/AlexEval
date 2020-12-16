#include "FCScurve.h"

FCScurve::FCScurve()
{
    this->name="name";
    FCSparams=NULL;
    numberOfPhotonsUsed=0;
}


FCScurve::FCScurve(QString name, FCSparams_t *params)
{
    this->name=name;
    FCSparams=params;
    numberOfPhotonsUsed=0;
}

