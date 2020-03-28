/**********************
 * 模数转化参考博客
 *  https://blog.csdn.net/qq_23937195/article/details/69950396
 *  Description:从串口A0 A1 GPIO12 口读入摇杆数据并通过串口输出
 *  GPIO12 一定要拉高，接入，否者会导致电压不稳读数失败
 ********************/

/* 定义串口发送编码 */
/*
#define CAR_ADVANCE '1'
#define CAR_BACK    '2'
#define CAR_RIGHT    '3'
#define CAR_LEFT     '4'
#define CAR_STOP    '0'
 */
/************************************************* 
Function: void get_rocker(int *buff)
Description: 获取摇杆按钮状态(12针) x轴数据(A0针) y轴数据(A1) 并存储于
Calls:  digitalRead()
        analogRead()
Table Accessed: // 被访问的表（ 
Table Updated: // 被修改的表（此项仅对于牵扯到数据库操作的程序） 
Input: buff 整型指针，获取一个指向3*sizeof(int)大小的存储空间
Output: buff[0] 摇杆是否被按下 1-按钮未按下 0-按钮被按下
        buff[1] 存储x轴数据 max=2^10-1=1023 min=0
        buff[2] 存储y轴数据 max=2^10-1=1023 min=0
Return: void
Others: void
*/
void get_rocker(int *buff)
{
  buff[0]=digitalRead(12);
  buff[1]=analogRead(0);
  buff[2]=analogRead(1);
}

int decide(){
  int rocker_data[3];           //用于临时存储摇杆x轴y轴以及switch状态
  get_rocker(rocker_data);      //传递存储摇杆状态的数组首地址
  int var=999; //调试用的利器
  if(rocker_data[1]>600){
    //Serial.println(CAR_ADVANCE);
    var = 1;
  }else if(rocker_data[1]<300) {
    //Serial.println(CAR_BACK);
    var = 2;
  }
  //判断摇杆x轴状态 >这里定义>600表示正推 <300表示反推
  if(rocker_data[2]>600){
    //Serial.println(CAR_RIGHT);
    var = 3;
  }else if(rocker_data[2]<300) {
    //Serial.println(CAR_LEFT);
    var = 4;
  }
  //判断摇杆按钮状态 当按钮被按下，
  //读取值为0 则经过逻辑非'!'运算取非，值变为真(0为假)，则串口输出数据
  if(!rocker_data[0]){
    //Serial.println(CAR_STOP);
   int rocker_data[3] = {0,0,1};
    var = 5;
  }
  //一般玩家手指反应时间长于100ms，因此定义延时100ms
  //建议定义延时是为了避免串口发送保持忙碌，给接收端处理数据时间
  //具体延时时间视情况而定
  
  return var;
  
}
