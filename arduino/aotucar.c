 /****************运动函数********************/
 /*

@向前，A/B/C/D四个轮子都向前运动

 */
void  forward(int i){

   digitalWrite(left1_1,HIGH); 
   digitalWrite(left1_2,LOW);  
   analogWrite(left1_pwm,i);
   digitalWrite(right1_1,HIGH); 
   digitalWrite(right1_2,LOW);  
   analogWrite(left2_pwm,i);
   digitalWrite(left2_1,HIGH); 
   digitalWrite(left2_2,LOW);  
   analogWrite(right1_pwm,i);
   digitalWrite(right2_1,HIGH);
   digitalWrite(right2_2,LOW);  
   analogWrite(right2_pwm,i);
  }

/************* 
@向后，A/B/C/D四个轮子都向后运动

***************/
void back(int i){
   digitalWrite(left1_1,LOW); 
   digitalWrite(left1_2,HIGH);  
   analogWrite(left1_pwm,i);
   digitalWrite(right1_1,LOW); 
   digitalWrite(right1_2,HIGH);  
   analogWrite(left2_pwm,i);
   digitalWrite(left2_1,LOW); 
   digitalWrite(left2_2,HIGH);  
   analogWrite(right1_pwm,i);
   digitalWrite(right2_1,LOW);
   digitalWrite(right2_2,HIGH);  
   analogWrite(right2_pwm,i);
}
/*
@向左，A/D向前;C/D向后
*/
void left(int i){
   digitalWrite(left1_1,HIGH); 
   digitalWrite(left1_2,LOW);  
   analogWrite(left1_pwm,i);
   digitalWrite(right1_1,LOW); 
   digitalWrite(right1_2,HIGH);  
   analogWrite(left2_pwm,i);
   digitalWrite(left2_1,LOW); 
   digitalWrite(left2_2,HIGH);  
   analogWrite(right1_pwm,i);
   digitalWrite(right2_1,HIGH);
   digitalWrite(right2_2,LOW);  
   analogWrite(right2_pwm,i);
}
/*
@向右 A/D向后，C/B向前
*/
void right(){
   digitalWrite(left1_1,LOW); 
   digitalWrite(left1_2,HIGH);  
   analogWrite(left1_pwm,i);
   digitalWrite(right1_1,HIGH); 
   digitalWrite(right1_2,LOW);  
   analogWrite(left2_pwm,i);
   digitalWrite(left2_1,HIGH); 
   digitalWrite(left2_2,LOW);  
   analogWrite(right1_pwm,i);
   digitalWrite(right2_1,HIGH);
   digitalWrite(right2_2,LOW);  
   analogWrite(right2_pwm,i);
}
/*
@几何中心旋转 A/D向后，C/B前
*/