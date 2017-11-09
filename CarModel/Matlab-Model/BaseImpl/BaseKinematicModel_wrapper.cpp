

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
#include "../../includes/kinematicmodel.h"
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
void BaseKinematicModel_Outputs_wrapper(const real_T *radius,
			const real_T *length,
			const real_T *distanceLR,
			const real_T *angularVR,
			const real_T *angularVL,
			const real_T *u1,
			const real_T *theta,
			const real_T *u2,
			real_T *longVeloc,
			real_T *rotationalVelocity,
			real_T *dX,
			real_T *dY,
			real_T *dTheta,
			real_T *dPhie)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
*/
using namespace Path::KinematicModels;
CarDescription car;
car.setRadius(radius[0]);
car.setLength(length[0]);
car.setDistLR(distanceLR[0]);
KinematicModel model;
model.setCarDesc(&car);
model.setAngularVL(angularVR[0]);
model.setAngularVR(angularVR[0]);
model.setTheta(theta[0]);
model.setU1(u1[0]);
model.setU2(u2[0]);
longVeloc[0] = model.longVelocity();
rotationalVelocity[0] = model.rotationalVelocity();
dX[0] = model.dX();
dY[0] = model.dY();
dTheta[0] = model.dTheta();
dPhie[0] = model.dPhie();
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
