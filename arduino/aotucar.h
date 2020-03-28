#ifndef _AOTUCAR_H
#define _AOTUCAR_H
#endif
/************定义全局变量****************/
//定义四个引脚的pwm波
#define left1_pwm 2
#define left2_pwm 3
#define right1_pwm 4
#define right2_pwm  5
//定义pwm波的值
#define i 100
//定义蓝牙读取值
char val=0;
//定义正反转引脚

#define left1_1  22
#define left1_2  23
#define left2_1 24 
#define left2_2  25 
#define right1_1 26 
#define right1_2 27 
#define right2_1  28
#define right2_2  29
/****************运动函数***********/
void speed_set(int out ,int speed);
void forward();//向前
void back();//向后
void left();//向左平移
void right();// 向右平移
void turn_left();//向左旋转
void turn_right();//向右旋转
void car_stop();//停止
