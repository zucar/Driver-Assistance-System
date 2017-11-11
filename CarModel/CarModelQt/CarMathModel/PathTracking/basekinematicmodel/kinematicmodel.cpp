#include "kinematicmodel.h"

using namespace Path::KinematicModels;

double KinematicModel::longVelocity() const
{
    return (carDesc->getRadius() / 2.0) * (angularVL + angularVR);
}

double KinematicModel::rotationalVelocity() const
{
    return (carDesc->getRadius() / carDesc->getDistLR()) * (angularVL - angularVR);
}

double KinematicModel::dX() const
{
    return u1 * std::cos(toDegree(theta));
}

double KinematicModel::dY() const
{
    return u1 * std::sin(toDegree(theta));
}

double KinematicModel::dTheta() const
{
    return u1 * std::tan(toDegree(theta)) / carDesc->getLength();
}

double KinematicModel::dPhie() const
{
    return u2;
}

double KinematicModel::toDegree(const double &rad) const
{
    return rad * (180.0 / PI);
}

CarDescription *KinematicModel::getCarDesc() const
{
    return carDesc;
}

void KinematicModel::setCarDesc(CarDescription *value)
{
    carDesc = value;
}

double KinematicModel::getAngularVL() const
{
    return angularVL;
}

void KinematicModel::setAngularVL(double value)
{
    angularVL = value;
}

double KinematicModel::getAngularVR() const
{
    return angularVR;
}

void KinematicModel::setAngularVR(double value)
{
    angularVR = value;
}

double KinematicModel::getTheta() const
{
    return theta;
}

void KinematicModel::setTheta(double value)
{
    theta = value;
}

double KinematicModel::getU1() const
{
    return u1;
}

void KinematicModel::setU1(double value)
{
    u1 = value;
}

double KinematicModel::getU2() const
{
    return u2;
}

void KinematicModel::setU2(double value)
{
    u2 = value;
}
