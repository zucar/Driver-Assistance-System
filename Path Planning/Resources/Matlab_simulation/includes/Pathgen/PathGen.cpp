#include "../PathGen.h"
path::path(){} ;
path::~path(){} ;

path::path( Eigen::VectorXd const &xVals, Eigen::VectorXd  const &yVals){

    this->xVals = xVals ;
    this->yVals = yVals ;
    len = xVals.rows()-1 ;

    X_MIN =  xVals.minCoeff();
    X_MAX =  xVals.maxCoeff();
    myPath = Eigen::SplineFitting<Eigen::Spline<double, 1,3>>::Interpolate(yVals.transpose(), 3,
                                                scaled_values(xVals));

}


void path::getpoints(const Eigen::VectorXd &xVals, const Eigen::VectorXd &yVals){
    this->xVals = xVals ;
    this->yVals = yVals ;

}
double path::operator()(double x) const {
    return myPath(scaled_value(x))(0);
  }
Eigen::VectorXd path::driv(double x){
    return myPath.derivatives(scaled_value(x) , 3);
}
void path::getDriv(double x){
    Eigen::VectorXd drivs =  myPath.derivatives(scaled_value(x),3) ;
    this->d1 = drivs(1) ;
    this->d2 = drivs(2) ;
    this->d3 = drivs(3) ;
    d1 = d1/len ;
    d2 = d2/std::pow(len,2.0) ;
    d3 = d3/std::pow(len,3.0) ;
}
double path::getfirstdriv(double x){
    getDriv(x);
    return this->d1 ;
}
double path::getSecDriv(double x){
    getDriv(x);
    return this->d2 ;
}
double path::getThirdDriv(double x){
    getDriv(x);
    return this->d3 ;
}
double path::calcCurvature(double x){
    getDriv(x);
    return std::abs(d2/std::pow(1.0+pow(d1,2),1.5));
}
double path::calcTorsion(double x){
    double T  = 0 ;
    double k = calcCurvature(x) ;
    double v = 1.0+pow(d1,2);

    T = (d3/d2)*k -3*d2*k*std::pow(v,4.0) ;
    return T ;

}
Eigen::RowVectorXd path::scaled_values(Eigen::VectorXd const &xVals) const{
    return xVals.unaryExpr([this](double x) { return scaled_value(x); }).transpose();
}
double path::scaled_value(double x) const{
     return (x - X_MIN) / (X_MAX - X_MIN);
}
