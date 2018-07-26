#ifndef KINEMATICMODEL_H
#define KINEMATICMODEL_H
#include "includes/cardescription.h"

namespace Path {
namespace KinematicModels {
class DECLAR_LIB KinematicModel;
}
}
class Path::KinematicModels::KinematicModel{
    const double PI = 22.0 / 7;
public:
    virtual double longVelocity() const;
    virtual double rotationalVelocity() const;
    virtual double dX() const;
    virtual double dY() const;
    virtual double dTheta() const;
    virtual double dPhie() const;
    virtual double toDegree(const double& rad) const;
    CarDescription *getCarDesc() const;
    void setCarDesc(CarDescription *value);

    double getAngularVL() const;
    void setAngularVL(double value);

    double getAngularVR() const;
    void setAngularVR(double value);

    double getTheta() const;
    void setTheta(double value);

    double getU1() const;
    void setU1(double value);

    double getU2() const;
    void setU2(double value);

    double getPhie() const;
    void setPhie(double value);

private:
    CarDescription *carDesc;
    double angularVL;
    double angularVR;
    double u1, theta, u2, phie;
protected:
};

#endif // KINEMATICMODEL_H
