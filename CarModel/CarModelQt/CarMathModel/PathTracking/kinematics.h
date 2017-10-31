#ifndef KINEMATICS_H
#define KINEMATICS_H
#include "pathtracking_global.h"
#include <cmath>
/*!
 * \brief GLobal Namespace For All Car-like Robot Calculations
 *
 */
namespace Path {
    /*! \brief Kinematic Model namespace.
     *  \author Mohamed Khaled.
     *  \details This Namespace Describes The Basic General Kinematic functions for car like \b robots.
     *
     */
    namespace KinematicModel {
        template<typename Num> Num DECLAR_LIB longVelocity(const Num& r, const Num& angularVL, const Num& angularVR);
        template<typename Num> Num DECLAR_LIB rotationalVelocity(const Num& r, const Num& dLR, const Num& angularVL, const Num& angularVR);
        template<typename Num, typename Degree> Num DECLAR_LIB dX(const Num& u1, const Degree& theta);
        template<typename Num, typename Degree> Num DECLAR_LIB dY(const Num& u1, const Degree& theta);
        template<typename Num, typename Degree> Num DECLAR_LIB dTheta(const Num& u1, const Num& lnth, const Degree& theta);
        template<typename Num> Num DECLAR_LIB dPhie(const Num& u2);
    }
}
using namespace Path::KinematicModel;
/*! \brief this Function is used To Cacluate Longitudinal Velocity of veichle.
 *  \details This Is a template function used to calculate the longitudinal Velocity of Robot according to the relation
 *  \param Num describes The Type of return and other parameters
 *  \param r describes The radius of wheeles used in the car.
 * \param angularVL angular velocity of left Wheel.
 * \param angularVR angular velocity of right Wheel.
 * \return the Longtiudnal of car Velocity.
 * \author Mohamed Khaled.
 */
template<typename Num> Num longVelocity(const Num& r, const Num& angularVL, const Num& angularVR)
{
    return (r / 2.0) * (angularVL + angularVR);
}
/*! \brief This template function used to calculate Rotational Velocity of robot
 *  \details the function uses the formula u2 =r/2R * (ψ˙r −ψ˙l).
 *  \param r describes the radius of the wheel.
 *  \param dLR describes the distance between the left and right wheels
 *  \param angularVL angular velocity of left Wheel.
 *  \param angularVR angular velocity of right Wheel.
 *  \return the Velocity of rotation.
 *  \author Mohamed Khaled.
 *
 */
template<typename Num> Num rotationalVelocity(const Num& r, const Num& dLR, const Num& angularVL, const Num& angularVR)
{
    return (r / dLR) * (angularVL - angularVR);
}
/*!
 *
 */
template<typename Num, typename Degree> Num dX(const Num& u1, const Degree& theta)
{
        return u1 * std::cos(theta);
}

template<typename Num, typename Degree> Num DECLAR_LIB dY(const Num& u1, const Degree& theta)
{
    return u1 * std::sin(theta);
}

template<typename Num, typename Degree> Num dTheta(const Num& u1, const Num& lnth,const Degree& theta)
{
    return u1 * std::tan(theta) / lnth;
}

template<typename Num> Num dPhie(const Num& u2)
{
    return u2;
}

#endif // KINEMATICS_H
