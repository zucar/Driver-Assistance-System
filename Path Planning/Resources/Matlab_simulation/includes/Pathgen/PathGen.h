#ifndef PATHGEN_H
#define PATHGEN_H
#include "C:/eigen-eigen-5a0156e40feb/Eigen/Core"
#include "C:/eigen-eigen-5a0156e40feb/unsupported/Eigen/Splines"

class path{
public:
     path() ;
     ~path() ;
     path(Eigen::VectorXd const &xVals , Eigen::VectorXd const &yVals ) ;
     void getpoints(Eigen::VectorXd const &xVals , Eigen::VectorXd const &yVals) ;
     void getDriv(double x) ;
     double getfirstdriv(double x) ;
     double getSecDriv(double x) ;
     double getThirdDriv(double x) ;
     double operator()(double x) const ;
     double calcCurvature(double x) ;
     double calcTorsion(double x) ;

private:
    double d1 , d2 , d3 ;
    double X_MIN;
    double X_MAX;
    int len = 0 ;
    Eigen::VectorXd xVals ;
    Eigen::VectorXd yVals ;
    Eigen::Spline<double, 1 , 3> myPath;
    double scaled_value(double x) const ;
    Eigen::RowVectorXd scaled_values(Eigen::VectorXd const &xVals) const ;
    Eigen::VectorXd driv(double x) ;


};







#endif
