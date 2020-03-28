#include "car.h"

Car_motor::Car_motor(int motornum){
    int num;
    num = motornum;
    switch (num){
        case 1:
        pinMode(MOTOR1_A,OUTPUT);
        pinMode(MOTOR1_B,OUTPUT);
        break;
        case 2:
        pinMode(MOTOR2_A,OUTPUT);
        pinMode(MOTOR2_B,OUTPUT);
        break;
        case 3:
        pinMode(MOTOR3_A,OUTPUT);
        pinMode(MOTOR3_B,OUTPUT);
        break;
        case 4:
        pinMode(MOTOR3_A,OUTPUT);
        pinMode(MOTOR3_B,OUTPUT);
        break;
    }
}

void Car_motor::run(int cmd) {
  int  a, b;
  switch (motornum) {
  case 1:
    a = MOTOR1_A; b = MOTOR1_B; break;
  case 2:
    a = MOTOR2_A; b = MOTOR2_B; break;
  case 3:
    a = MOTOR3_A; b = MOTOR3_B; break;
  case 4:
    a = MOTOR4_A; b = MOTOR4_B; break;
  default:
    return; //错误
  }
 switch (cmd){
    case FORWARD:
    digitalWrite(a,HIGH);
    digitalWrite(b,LOW);
    break;
    case BACKWARD:
    digitalWrite(a,LOW);
    digitalWrite(b,HIGH);
    break;
    case RELEASE:
    digitalWrite(a,LOW);
    digitalWrite(b,LOW);
    break;
 } 
}
void Car_motor::setSpeed(int speed) {
  switch (motornum) {
  case 1:
    analogWrite(setpwm1,speed);break;
  case 2:
    analogWrite(setpwm2,speed); break;
  case 3:
    analogWrite(setpwm3,speed); break;
  case 4:
    analogWrite(setpwm4,speed);break;
  }
}
