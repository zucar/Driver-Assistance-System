#include "parking.h"
volatile uint32_t counter  = 0 ;
PARKING::PARKING(){};
PARKING::~PARKING(){};

void PARKING::searchForLot(DC_MOTOR Wheel, NewPing sonar){
        int temp = 0 ; 
        int lotCounter =  0 ;
        calcThreshold(Wheel);
        Serial.print("threshold: ");
        Serial.println(this->threshold);
        counter = 0 ;
    while(this->startSearch == true){
        Wheel.moveForward();
        while((temp = sonar.ping_cm()) < this->carWidth_cm){
             
            obsDist = temp ;
            Serial.println(obsDist); 
        }
        overallDistance = counter ; 
        counter = 0 ;
        while ((this->depth = sonar.ping_cm()) > this->carWidth_cm) {
             //Serial.print("obs : ");
           // Serial.println(counter);
             Serial.println(depth);
            
            if(counter >= this->threshold ){
             //   Serial.println("i'm here..");
                lotCounter = counter ;
           //     Serial.println(counter);
                this->validLot = true ;
                Wheel.stop();
                this->startSearch = false ;
                delay(1000);
                  Serial.print("xx ; ") ;
                  Serial.println(overallDistance) ; 
                  Serial.println(counter) ; 
                  this->overallDistance = (this->overallDistance + counter)*(69.0/80.0) ; 
                 //Serial.println("counter after stop = ");
                 //Serial.println(counter);
                break;
            }
        }

        if(this->validLot == true){
            delay(500);
            this->calcLotDepth();
            this->calcLotWidth(lotCounter,Wheel);
            this->calcLotX(Wheel);
            this->calcLotY();
           
        }
    }

}



void PARKING::calcLotDepth(){
    this->lotDepth = this->depth - this->obsDist ;
}


void PARKING::calcLotWidth(int count ,DC_MOTOR Wheel ){
    this->lotWidth = count*2*PI*(Wheel.WHEELRADUIS/Wheel.PPR) ;
}



void PARKING::calcLotX(DC_MOTOR Wheel){
    this->lotX= (counter*2*PI*(Wheel.WHEELRADUIS/Wheel.PPR)) - this->carLength_cm/2.0 ;

}


void PARKING::calcLotY(){
    this->lotY = this->depth - this->carLength_cm/2.0 ;
}
void PARKING::reset(){
    this->depth = 0 ;
    this->lotDepth = 0 ;
    this->lotWidth = 0 ;
    this->validLot = false ;
    this->lotX = 0 ;
    this->lotY = 0 ;
    this->obsDist = 0 ;
    this->startSearch = false ;
}

void PARKING::calcThreshold(DC_MOTOR Wheel){
    this->threshold = (int)((this->carLength_cm/(2*PI*Wheel.WHEELRADUIS))*Wheel.PPR) ;
}
