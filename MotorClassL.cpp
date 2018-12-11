
#include "MotorClassL.h" 
//#include "AFMotor.h"
 
//AF_DCMotor motorL(1);
//AF_DCMotor motorR(2); 
 int motor_rightEnable=7;
    int motor_rightF=6;
    int motor_rightB=5;
    
    int motor_leftEnable=8;
    int motor_leftF=3;
    int motor_leftB=2;
void MotorClassL::motorForward(int a,int b ){
    if(a<0)
    {
        //motorL.run(BACKWARD);
        //digitalWrite(motor_rightEnable,HIGH);
        digitalWrite(motor_leftEnable,HIGH);
        analogWrite(motor_leftF,0);
        analogWrite(motor_leftB,a);
        Serial.print("Print A<0");
       // motorL.setSpeed(-a);
    }
    else
    {
      //  digitalWrite(motor_rightEnable,LOW);
        digitalWrite(motor_leftEnable,HIGH);
        analogWrite(motor_leftB,0);
        analogWrite(motor_leftF,a);
    }
    if(b<0)
    {
        digitalWrite(motor_rightEnable,HIGH);
       // digitalWrite(motor_leftEnable,LOW);
       analogWrite(motor_rightF,0);
        analogWrite(motor_rightB,b);
        Serial.print("Print B<0");
    }
    else
    {
       digitalWrite(motor_rightEnable,HIGH);
      //  digitalWrite(motor_leftEnable,LOW);
      analogWrite(motor_rightB,0);
        analogWrite(motor_rightF,b);
      //  motorR.run(FORWARD);
       // motorR.setSpeed(b);
    }
}
void MotorClassL::motorLForward(int a){
    if(a<0)
    {
         // digitalWrite(motor_rightEnable,LOW);
        digitalWrite(motor_leftEnable,HIGH);
        analogWrite(motor_leftB,a);
    }
    else
    {
       // digitalWrite(motor_rightEnable,LOW);
        digitalWrite(motor_leftEnable,HIGH);
        analogWrite(motor_leftF,a);
    }
}
void MotorClassL::motorRForward(int b){
    if(b<0)
    {
         digitalWrite(motor_rightEnable,HIGH);
       // digitalWrite(motor_leftEnable,LOW);
        analogWrite(motor_rightB,b);
    }
    else
    {
        digitalWrite(motor_rightEnable,HIGH);
      //  digitalWrite(motor_leftEnable,LOW);
        analogWrite(motor_rightF,b);
    }
}
void MotorClassL::tiltLft(int b){
  /*  motorL.run(FORWARD);
    motorR.run(FORWARD);
    motorL.setSpeed(0);
    motorR.setSpeed(b);*/
    digitalWrite(motor_rightEnable,HIGH);
        digitalWrite(motor_leftEnable,HIGH);
        analogWrite(motor_leftF,0);
        analogWrite(motor_rightF,b);
}
void MotorClassL::tiltRyt(int a){
digitalWrite(motor_rightEnable,HIGH);
        digitalWrite(motor_leftEnable,HIGH);
        analogWrite(motor_leftF,a);
        analogWrite(motor_rightF,0);
}
void MotorClassL::brake(){
 digitalWrite(motor_rightEnable,LOW);
        digitalWrite(motor_leftEnable,LOW);
        analogWrite(motor_leftF,0);
        analogWrite(motor_rightF,0);
}
void MotorClassL::motorLBrake(){
   digitalWrite(motor_leftEnable,LOW);
        analogWrite(motor_leftF,0);
}
void MotorClassL::motorRBrake(){
  digitalWrite(motor_rightEnable,LOW);
        analogWrite(motor_rightF,0);
}


