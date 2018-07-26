#ifndef CARKINEMATICS_H
#define CARKINEMATICS_H
#include "../pathtracking_global.h" 
#include <cmath>

namespace Path{
namespace RControl {
    template<typename Num> Num DECLAR_LIB calcZ1(const Num&  s) ;
    template<typename Num> Num DECLAR_LIB calcZ2(const Num&  d) ;
    template<typename Num> Num DECLAR_LIB calcZ3(const Num&  d , const Num&  s , const Num&  thetaE  ) ;
    template<typename Num> Num DECLAR_LIB calcZ4(const Num&  d , const Num&  s , const Num&  thetaE  , const Num&  phi   , const Num& L , const Num& curvature , const Num& curvatureDF  ) ;
    template<typename Num> Num DECLAR_LIB controlSignal_V2(const Num&  v1  ,const  Num& k2,const  Num& k3,const Num& K4,const  Num& z2,const  Num& z3,const  Num& z4);
    template<typename Num> Num DECLAR_LIB calcV1(const Num& u1 , const Num& curvature , const Num& d , const Num& thetaE );



template<typename Num> Num calcZ1(const Num&  s) {
        return s  ; 
    }
template<typename Num> Num calcZ2(const Num&  d) {
        return d  ; 
    }
template<typename Num> Num calcZ3(const Num&  d , const Num&  s , const Num&  thetaE , const  Num& curvature )
    {
        return  (1-d*curvature)*std::tan(thetaE*3.14/180.0) ;
    }
template<typename Num>Num  calcZ4(const Num&  d , const Num&  s , const Num&  thetaE  , const Num&  phi   , const Num& L , const Num& curvature , const Num& curvatureDF  )
    {
    return  -curvature*(1-d*curvature)*(1+std::pow(std::tan(thetaE),2.0))-d*curvatureDF*std::tan(thetaE)+std::pow((1-d*curvature),2.0)*(std::tan(phi)/(L*std::pow(cos(thetaE*3.14/180.0),3.0)));
    }

template<typename Num> Num controlSignal_V2(const Num&  v1  ,const  Num& k2,const  Num& k3,const  Num& k4 ,const  Num& z2,const  Num& z3,const  Num& z4){
            return std::abs(v1)*k2*z2 - v1*k3*z3 - std::abs(v1)*k4*z4  ; 
        }


template<typename Num> Num calcV1(const Num& u1 , const Num& curvature , const Num& d , const Num& thetaE ){
            return u1/(1-d*curvature*std::cos(thetaE*3.14/180));

   }
/*

template<typename Num> Num calacZ2Dot(){}
template<typename Num> Num calacZ2Dot(){}
template<typename Num> Num calacZ2Dot(){}
*/

        
}}
#endif // CARKINEMATICS_H
