#include "dc_motor.h"
#include "NewPing.h"
#include "PARKING.h"
#define dirPin 6
#define pwmPin 5  
#define encoderPin 2 
#define TRIGGER_PIN 9  
#define ECHO_PIN 8 
#define MAX_DISTANCE 300 
//temp var

bool startSearch = false ; 
bool validLot = false ; 
//
volatile uint32_t c = 0 ; 
char t = ' ' ; 
DC_MOTOR Wheel ; 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
PARKING carPark ; 
void setup() {
  Wheel.attach(dirPin,pwmPin,encoderPin) ; 
  attachInterrupt(0, Wheel_ISR , RISING) ; 
  Serial.begin(9600);
  Wheel.stop();
}

void loop() {
  while(Serial.available()<=0); 
    t = Serial.read();
    if(t=='b'){ Wheel.moveBackward() ; delay(1500); Wheel.stop() ;} 
    if(t=='f'){ Wheel.moveForward() ; delay(500); Wheel.stop() ;} 
    if(t == 's'){carPark.startSearch = true;} 
    t = ' ' ; 
    
    
    carPark.searchForLot(Wheel,sonar);
    if(carPark.validLot == true ){
      Serial.print("lot width = ");
      Serial.println(carPark.lotWidth);
      Serial.print("lot depth : ");
      Serial.println(carPark.lotDepth);
      Serial.print("LOTX = ");
      Serial.println(carPark.lotX);
      Serial.print("LOTY = ");
      Serial.println(carPark.lotY);
       Serial.print("dist = ");
      Serial.println(carPark.overallDistance);
      carPark.reset();
      
      }
    
}

void searchForLot(DC_MOTOR Wheel, NewPing sonar){
        int lotCounter =  0 ;
        int obsDist = 0 ;
      //  calcThreshold(Wheel);
      //  Serial.print("threshold: ");
      //  Serial.println(this->threshold);
    while(startSearch == true){
        counter = 0 ;
        Wheel.moveForward();
        while((obsDist = sonar.ping_cm()) < 20){
            Serial.println(obsDist);
        }
        counter = 0 ;
        while (obsDist = sonar.ping_cm() > 20) {
             //Serial.print("obs : ");
            Serial.println(obsDist);
            
            if(counter >= 60 ){
                Serial.println("i'm here..");
                lotCounter = counter ;
                validLot = true ;
                Wheel.stop();
                startSearch = false ;
                delay(50);
                break;
            }
        }
        }
      } 


void Wheel_ISR(){
      counter++ ;
     // Serial.println(counter);
  }
