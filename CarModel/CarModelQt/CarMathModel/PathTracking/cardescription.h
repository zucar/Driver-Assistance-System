#ifndef CARDESCRIPTION_H
#define CARDESCRIPTION_H
#include "pathtracking_global.h"
namespace Path {
namespace KinematicModels {
        class DECLAR_LIB CarDescription;
    }
}
/*!
 * \brief The Path::KinematicModels::CarDescription class is used To Encapsulate Car Descriptions
 */
//TODO USE PIMPL IF The Doc Approved
class Path::KinematicModels::CarDescription{
 private:
    double r;
    double lnth;
    double dLR;
public:

    double getRadius() const;
    void setRadius(double value);

    double getLength() const;
    void setLength(double value);

    double getDistLR() const;
    void setDistLR(double value);

protected:
};
#endif // CARDESCRIPTION_H
