#ifndef PARKING_H
#define PARKING_H
#include "dc_motor.h"
#include "NewPing.h"
extern volatile uint32_t counter ;

class PARKING
{
public:
    int overallDistance = 0 ;  
    float lotWidth  = 0  ;
    float wheelRaduis = 11.1 ;
    float lotDepth = 0 ;
    float lotX = 0 ;  //Horizontal distance form car center to parking lot center
    float lotY  = 0 ; //Vertical ditance from car lot center to ////////////////
    int carLength_cm = 30 ;
    int carWidth_cm = 30 ;
    int depth = 0;
    int obsDist = 0;
    int threshold = 0 ;
    bool validLot = false ;
    bool startSearch = false ;
      PARKING();
      ~PARKING();
    void searchForLot(DC_MOTOR Wheel,NewPing sonar);
    void reset();
private:
    int LotEncPulses = 0 ;
    void calcLotWidth(int count ,DC_MOTOR Wheel) ;
    void calcLotDepth();
    void calcLotX(DC_MOTOR Wheel);
    void calcLotY();
    void calcThreshold(DC_MOTOR Wheel);


};

#endif // PARKING_H
