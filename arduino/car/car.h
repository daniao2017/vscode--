#ifndef _CAR_H_
#define _CAR_H_
/*  电机驱动          */
#include<Arduino.h>
#define MOTOR1_A 22
#define MOTOR1_B 23
#define MOTOR2_A 24
#define MOTOR2_B 25
#define MOTOR3_A 26
#define MOTOR3_B 27
#define MOTOR4_A 28
#define MOTOR4_B 29
/*pwm设置*/
#define setpwm1 4
#define setpwm2 5
#define setpwm3 6
#define setpwm4 7
/* 方向设置 */
#define FORWARD 1
#define BACKWARD 2
#define RELEASE 3

class Car_motor{
    public:
    Car_motor(int motornum );
    void run(int cmd );
    void setSpeed(int speed);

    private:
    int motornum;

};
#endif
