#include <mex.h>
#include <iostream>
#include <cmath>
#include "kinematics.h"
using namespace std;
using namespace Path::KinematicModel;
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){
{
    if (nrhs != 3) {
           mexErrMsgIdAndTxt("MATLAB:mexcpp:nargin",
                   "requires 3 input arguments.");
         } else if (nlhs >= 1) {
           mexErrMsgIdAndTxt("MATLAB:mexcpp:nargout",
                   "MEXCPP requires one output argument.");
         }
    double r, angularVL, angularVR;
    r = (double *) mxGetPr(prhs[0]);
    angularVL = (double *) mxGetPr(prhs[1]);
    angularVR = (double *) mxGetPr(prhs[2]);
    auto ret = longVelocity(*r, *angularVL, *angularVR);
    plhs[0] = mxCreateDoubleScalar(ret);
}
