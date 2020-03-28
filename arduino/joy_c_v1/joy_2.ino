#include"aotucar.h"
#include"joy.c"
void setup() {
  Serial.begin(115200);
  pinMode(12,INPUT);
  digitalWrite(12,HIGH);//上拉
}
void loop(){
  int test;
   test = decide();
   Serial.println(test);
   delay(1000);

}
