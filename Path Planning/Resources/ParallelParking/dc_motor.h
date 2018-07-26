#ifndef DC_MOTOR_H
#define DC_MOTOR_H
#define FORWARWD  1
#define BACKWORD 0
#include <Arduino.h>

class DC_MOTOR
{
public:
    int PPR = 75 ;
    float WHEELRADUIS = 11.1 ;
    //volatile uint32_t counter = 0 ;
    DC_MOTOR();
    ~DC_MOTOR();
    void attach(const byte dirPin ,const byte pwmPin , const byte encoderPin);
    void moveForward();
    void moveBackward();
    void move(int dir);
    void move(int dir , int speed  , int distance) ;
    void stop();
    void reverseDir();
    void setSpeed(short SPEED_PWM);

private :
    int DIR  = FORWARWD ;
    float SPEED_MS = 0 ;
    short SPEED_PWM = 120 ;
    byte dirPin ;
    byte pwmPin ;
    byte encoderPin ;

};
#endif // DC_MOTOR_H
