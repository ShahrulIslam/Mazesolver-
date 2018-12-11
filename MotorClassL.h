#ifndef MotorClassL_h
#define MotorClassL_h
#include <Arduino.h>

class MotorClassL{
public : 
    void motorForward(int a,int b );
    void motorLForward(int a);
    void motorRForward(int b);
    void tiltRyt(int a);
    void tiltLft(int b);
    void brake(); 
    void motorLBrake();
    void motorRBrake();
   
    
    
   
};

#endif
