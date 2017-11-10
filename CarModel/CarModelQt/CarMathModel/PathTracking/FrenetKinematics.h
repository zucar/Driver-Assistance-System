#ifndef CKINEMATICS_H
#define CKINEMATICS_H

#include <pathtracking_global.h>

namespace Path {
    namespace FrenetModel {

    /*! \brief this function is used to calculate differntial of S .
     *  \details the Template function uses the formula \b S˙ = ( u1 / ( 1-dc(s) ) ) * ( cos(θe) - ( (tanφ)/L) * ( l2*cos(θe) + l1*sin(θe) ) ) .
     *  \param u1 the longitudianl velocity of the robot
     *  \param lnth the distance between front wheels and rear wheels axle.
     *  \param phie The Vehicle's steering angle.
     *  \param theta_e the angle characterizing the orientation of the robot chassis with respect to the fram Fs.
     *  \param l1 the coordinate of P (l1,l2) expressed in the basis of Fm.
     *  \param l2 the coordinate of P (l1,l2) expressed in the basis of Fm.
     *  \param dc is the differential eq of the curvature c(S)
     *  \return of Type Num the current diffrential.
     *  \author Sherif Abaza.
     */
    template <typename Num , typename Degree> Num dS(const Num& u1 , const Num& dc , const Degree& theta_e , const Degree& phie , const Num& lnth , const Num& l1 , const Num& l2){
        return ( u1/(1-dc) * (std::cos(theta_e) - (std::tan(phie)/lnth)*(l2*std::cos(theta_e) + l1*std::sin(theta_e))));
    }

    /*! \brief this function is used to calculate differntial of d .
     *  \details the Template function uses the formula \b d˙ =  u1 * ( sin(θe) + ( (tanφ)/L) * ( l1*cos(θe) - l2*sin(θe) ) ) ) .
     *  \param u1 the longitudianl velocity of the robot
     *  \param lnth the distance between front wheels and rear wheels axle.
     *  \param phie The Vehicle's steering angle.
     *  \param theta_e the angle characterizing the orientation of the robot chassis with respect to the fram Fs.
     *  \param l1 the coordinate of P (l1,l2) expressed in the basis of Fm.
     *  \param l2 the coordinate of P (l1,l2) expressed in the basis of Fm.
     *  \return of Type Num the current diffrential.
     *  \author Sherif Abaza.
     */
    template <typename Num , typename Degree> Num dD(const Num& u1 , const Degree& theta_e , const Degree& phie , const Num& lnth , const Num& l1 , const Num& l2){
        return ( u1 * (std::sin(theta_e) + (std::tan(phie) / lnth) *(l1 * std::cos(theta_e) - l2*std::sin(theta_e))));
    }

    /*! \brief used to calclate differntial of Theta by time
     *  \details the Template function uses the formula \b θ˙ = (u1/L) * tanφ - S˙C(S) .
     *  \param u1 the longitudianl velocity of the robot
     *  \param lnth the distance between front wheels and rear wheels axle.
     *  \param phie The Vehicle's steering angle.
     *  \param sdot is the differential eqquation of the curvilinear abscissa
     *  \param c the curvature c(S) of C at Ps
     *  \return of Type Num the current diffrential.
     *  \author Sherif Abaza.
     */
    template<typename Num, typename Degree> Num dTheta(const Num& u1, const Num& lnth, const Degree& phie, const Degree& sdot, const Degree& c )
    {
        return ( (u1/lnth) * std::tan(phie) ) - sdot*c;
    }

    /*! \brief used to calclate dPhie
     *  \details the Template function uses the formula \b φ˙ = u2.
     *  \param u2 the angular velocity of the robot.
     *  \return of Type Num the current diffrential.
     *  \author Sherif Abaza.
     *
     */
    template<typename Num> Num dPhie(const Num& u2)
    {
        return u2;
    }

    }
}

#endif // CKINEMATICS_H
