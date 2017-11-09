#include "cardescription.h"
using namespace Path::KinematicModels;

double CarDescription::getRadius() const
{
    return r;

}

void CarDescription::setRadius(double value)
{
    r = value;
}

double CarDescription::getLength() const
{
    return lnth;
}

void CarDescription::setLength(double value)
{
    lnth = value;
}

double CarDescription::getDistLR() const
{
    return dLR;
}

void CarDescription::setDistLR(double value)
{
    dLR = value;
}
