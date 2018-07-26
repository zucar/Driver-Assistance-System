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
     *  \image html carkinematicmodel.png
     *  \par uses the equations
     *  <b>
     *   x˙ = u1 cosθ , <br/>
     *   y˙ = u1 sinθ , <br/>
     *   θ˙ = (u1/L) * tanφ , <br/>
     *   φ˙ = u2 , <br/>
     *  </b>
     *  \endparblock
     */


    namespace KinematicModels {
        template<typename Num> Num DECLAR_LIB longVelocity(const Num& r, const Num& angularVL, const Num& angularVR);
        template<typename Num> Num DECLAR_LIB rotationalVelocity(const Num& r, const Num& dLR, const Num& angularVL, const Num& angularVR);
        template<typename Num, typename Degree> Num DECLAR_LIB dX(const Num& u1, const Degree& theta);
        template<typename Num, typename Degree> Num DECLAR_LIB dY(const Num& u1, const Degree& theta);
        template<typename Num, typename Degree> Num DECLAR_LIB dTheta(const Num& u1, const Num& lnth, const Degree& theta);
        template<typename Num> Num DECLAR_LIB dPhie(const Num& u2);





    }
}
#include "kinematicimpls.h"
#endif // KINEMATICS_H
