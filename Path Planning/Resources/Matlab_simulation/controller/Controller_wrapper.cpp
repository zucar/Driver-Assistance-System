

/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include "../includes/carkinematics/carkinematics.h"
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void Controller_Outputs_wrapper(const real_T *d,
			const real_T *thetaE,
			const real_T *s,
			const real_T *cS,
			const real_T *phie,
			const real_T *u1,
			const real_T *cDE,
			real_T *v2,
			real_T *V1,
			const real_T  *K2, const int_T  p_width0,
			const real_T  *K3, const int_T  p_width1,
			const real_T  *K4, const int_T  p_width2,
			const real_T  *L, const int_T  p_width3)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
*/
using namespace Path::RControl;
double z1 ,z2, z3, z4, v1;
z2 = calcZ2(d[0]);
z3 = calcZ3(d[0], s[0], thetaE[0], cS[0]);
z4 = calcZ4(d[0], s[0], thetaE[0], phie[0],double(L[0]), cS[0], cDE[0]);
v1 = calcV1(u1[0] , cS[0], d[0] , thetaE[0]);
V1[0]= v1;
v2[0] = controlSignal_V2(v1 ,K2[0], K3[0], K4[0] ,z2,z3,z4);
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
