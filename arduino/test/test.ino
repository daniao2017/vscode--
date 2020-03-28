
/*  电机驱动          */
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
/*
void Car_motor(int motornum){
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

void run(int cmd) {
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
    case 1:
    digitalWrite(MOTOR1_A,HIGH);
    digitalWrite(MOTOR1_B,LOW);
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
void setSpeed(int speed) {
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

*/
void setup() {
        pinMode(MOTOR1_A,OUTPUT);
        pinMode(MOTOR1_B,OUTPUT);
}
void loop(){
  
  digitalWrite(MOTOR1_A,HIGH);
  digitalWrite(MOTOR1_B,LOW);
  delay(2000);
}
