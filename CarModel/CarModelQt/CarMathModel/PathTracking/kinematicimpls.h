#ifndef KINEMATICIMPLS_H
#define KINEMATICIMPLS_H
namespace Path {
namespace KinematicModel {

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
 *  \details the function uses the formula \b u2 =r/2R * (ψ˙r −ψ˙l).
 *  \param r describes the radius of the wheel.
 *  \param dLR describes the distance between the left and right wheels
 *  \param angularVL  angular velocity of left Wheel.
 *  \param angularVR  angular velocity of right Wheel.
 *  \return the Velocity of rotation.
 *  \author Mohamed Khaled.
 *
 */
template<typename Num> Num rotationalVelocity(const Num& r, const Num& dLR, const Num& angularVL, const Num& angularVR)
{
    return (r / dLR) * (angularVL - angularVR);
}
/*! \brief used to calclate diffrential of x by time
 *   \details the Template function uses the formula \b x˙ = u1 cosθ.
 * \param u1 the longitudinal velocity of the robot
 *  \param theta the angle of the robot chassis orientation .
 *  \return of Type Num the current diffrential.
 *  \author Mohamed Khaled.
 *
 */
template<typename Num, typename Degree> Num dX(const Num& u1, const Degree& theta)
{
    return u1 * std::cos(theta);
}
/*! \brief used to calclate dy
 *   \details the Template function uses the formula \b y˙ = u1 sinθ.
 *  \param theta the angle of the robot chassis orientation .
 *  \return of Type Num the current diffrential.
 *  \author Mohamed Khaled.
 *
 */
template<typename Num, typename Degree> Num dY(const Num& u1, const Degree& theta)
{
    return u1 * std::sin(theta);
}
/*! \brief used to calclate differntial of Theta by time
 *  \details the Template function uses the formula \b θ˙ = (u1/L) * tanφ .
 *  \param u1 the longitudianl velocity of the robot
 *  \param lngth the distance between front wheels and rear wheels axle.
 *  \param theta the angle of the robot chassis orientation .
 *  \return of Type Num the current diffrential.
 *  \author Mohamed Khaled.
 */
template<typename Num, typename Degree> Num dTheta(const Num& u1, const Num& lnth,const Degree& theta)
{
    return u1 * std::tan(theta) / lnth;
}
/*! \brief used to calclate dPhie
 *  \details the Template function uses the formula \b φ˙ = u2.
 *  \param u2 the angular velocity of the robot.
 *  \return of Type Num the current diffrential.
 *  \author Mohamed Khaled.
 *
 */
template<typename Num> Num dPhie(const Num& u2)
{
    return u2;
}

}
}
#endif // KINEMATICIMPLS_H
