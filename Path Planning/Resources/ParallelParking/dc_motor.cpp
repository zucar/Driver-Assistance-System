#include "dc_motor.h"


DC_MOTOR::DC_MOTOR(){};
DC_MOTOR::~DC_MOTOR(){};


void DC_MOTOR::attach(const byte dirPin ,const byte pwmPin , const byte encoderPin){
    this->dirPin = dirPin ;
    this->pwmPin = pwmPin ;
    this->encoderPin = encoderPin;
    pinMode(dirPin,OUTPUT);
    pinMode(pwmPin,OUTPUT);
    pinMode(encoderPin,INPUT_PULLUP) ;
}
void DC_MOTOR::moveForward(){
    digitalWrite(dirPin,HIGH);
    this->DIR = FORWARWD ;
    analogWrite(pwmPin,SPEED_PWM);
}
void DC_MOTOR::moveBackward(){
    digitalWrite(dirPin,LOW);
    this->DIR = FORWARWD ;
    analogWrite(pwmPin,SPEED_PWM);
}
void DC_MOTOR::move(int dir){
    analogWrite(pwmPin,SPEED_PWM);
}
void DC_MOTOR::move(int dir , int speed  , int distance){}
void DC_MOTOR::stop(){
    analogWrite(pwmPin,0);
}
void DC_MOTOR::reverseDir(){
    if(this->DIR == FORWARWD){
        this->DIR = BACKWORD ;
    }else {
        this->DIR = FORWARWD ;
    }

}

void DC_MOTOR::setSpeed(short speed_pwm){
    this->SPEED_PWM = speed_pwm ;
}
