#include <SoftwareSerial.h> 
// Pin10为RX，接HC05的TXD
// Pin11为TX，接HC05的RXD
SoftwareSerial BT(10, 11); 

/************定义全局变量****************/
//定义四个引脚的pwm波
int enA = 2;
int enB = 3;
int enC = 4;
int enD = 5;
//定义pwm波的值
int i = 100;
//定义蓝牙读取值
char val=0;
//定义正反转引脚
int input1 = 22; 
int input2 = 23;
int input3 = 24; 
int input4 = 25; 
int input5 = 26; 
int input6 = 27; 
int input7 = 28; 
int input8 = 29;
/******************初始化函数************/
void motor_init();//电机初始化函数
/****************运动函数***********/
void forward();//向前
void back();//向后
void left();//向左平移
void right();// 向右平移
void turn_left();//向左旋转
void turn_right();//向右旋转
void car_stop();//停止
/*******蓝牙匹配函数*******/
void blue_case();
/***************初始化函数*********/
void setup() {   
  motor_init();   
  Serial.begin(9600); 
  Serial.println("BT is ready!");
  // HC-05老版默认，38400,新版9600
  BT.begin(9600); 
}
/**********循环主函数*****************/
void loop() {
   if (BT.available()) {
    val = BT.read();
    Serial.print(val);//调试用
    if(val=='0'){car_stop();}
    if(val=='1'){forward();delay(500);car_stop();}
    if(val=='2'){ back();delay(500);car_stop();}
    if(val=='3'){ left();delay(500);car_stop();}
    if(val=='4'){ right();delay(500);car_stop();}
   }
  else
  car_stop(); 
}
//电机初始化函数
void motor_init(){
  pinMode(input1,OUTPUT);
   pinMode(input2,OUTPUT);
   pinMode(enA,OUTPUT);
   pinMode(input3,OUTPUT);
   pinMode(input4,OUTPUT);
   pinMode(enB,OUTPUT);
   pinMode(input5,OUTPUT);
   pinMode(input6,OUTPUT);
   pinMode(enC,OUTPUT);
   pinMode(input7,OUTPUT);
   pinMode(input8,OUTPUT);
   pinMode(enD,OUTPUT);
  }
 /****************运动函数********************/
 //向前
void  forward(){
   digitalWrite(input1,HIGH); 
   digitalWrite(input2,LOW);  
   analogWrite(enA,i);
   digitalWrite(input3,HIGH); 
   digitalWrite(input4,LOW);  
   analogWrite(enB,i);
      digitalWrite(input5,HIGH); 
   digitalWrite(input6,LOW);  
   analogWrite(enC,i);
      digitalWrite(input7,HIGH);
   digitalWrite(input8,LOW);  
   analogWrite(enD,i);
  }
  //向后
 void back(){
     digitalWrite(input1,LOW); 
   digitalWrite(input2,HIGH);  
   analogWrite(enA,i);
   digitalWrite(input3,LOW); 
   digitalWrite(input4,HIGH);  
   analogWrite(enB,i);
      digitalWrite(input5,LOW); 
   digitalWrite(input6,HIGH); 
   analogWrite(enC,i);
      digitalWrite(input7,LOW); 
   digitalWrite(input8,LOW);  
   analogWrite(enD,i);
  }
  //向左
 void left(){
    digitalWrite(input1,HIGH); 
   digitalWrite(input2,LOW);  
   analogWrite(enA,i);
   digitalWrite(input3,LOW); 
   digitalWrite(input4,HIGH);  
   analogWrite(enB,i);
digitalWrite(input5,LOW); 
   digitalWrite(input6,HIGH);  
   analogWrite(enC,i);
      digitalWrite(input7,HIGH);
   digitalWrite(input8,LOW);  
   analogWrite(enD,i);
   }
 //向右
void right(){
     digitalWrite(input1,LOW); 
   digitalWrite(input2,HIGH);  
   analogWrite(enA,i);
   digitalWrite(input3,HIGH); 
   digitalWrite(input4,LOW);  
   analogWrite(enB,i);
      digitalWrite(input5,HIGH); 
   digitalWrite(input6,LOW);  
   analogWrite(enC,i);
      digitalWrite(input7,LOW);
   digitalWrite(input8,HIGH);  
   analogWrite(enD,i);
  }
  //向右旋转
  void turn_right(){
     digitalWrite(input1,HIGH); 
   digitalWrite(input2,LOW);  
   analogWrite(enA,i);
   digitalWrite(input3,LOW); 
   digitalWrite(input4,HIGH);  
   analogWrite(enB,i);
      digitalWrite(input5,HIGH); 
   digitalWrite(input6,LOW);  
   analogWrite(enC,i);
      digitalWrite(input7,LOW);
   digitalWrite(input8,HIGH);  
   analogWrite(enD,i);   
    }
    //向左旋转
 void turn_left(){
   digitalWrite(input1,LOW); 
   digitalWrite(input2,HIGH);  
   analogWrite(enA,i);
   digitalWrite(input3,HIGH); 
   digitalWrite(input4,LOW);  
   analogWrite(enB,i);
   digitalWrite(input5,LOW); 
   digitalWrite(input6,HIGH);  
   analogWrite(enC,i);
    digitalWrite(input7,HIGH);
   digitalWrite(input8,LOW);  
   analogWrite(enD,i);
  }
void car_stop()
{
   digitalWrite(input1,LOW); 
   digitalWrite(input2,LOW);  
   digitalWrite(input3,LOW); 
   digitalWrite(input4,LOW);  
   digitalWrite(input5,LOW); 
   digitalWrite(input6,LOW);  
    digitalWrite(input7,LOW);
   digitalWrite(input8,LOW);  
  }

  
