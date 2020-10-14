/*----------------------------

给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
示例 1:
输入: 123
输出: 321
解题思路参见
https://leetcode-cn.com/problems/reverse-integer/solution/tu-jie-7-zheng-shu-fan-zhuan-by-wang_ni_ma/
https://leetcode-cn.com/problems/reverse-integer/solution/zheng-shu-fan-zhuan-by-xiao-yu-ying-ying-an-xiang-/

------------------------------*/
#include<stdio.h>
int main(){
    int input_int,out_int;
    printf("请输入你要反转的整数：");
    scanf("%d",&input_int); 
    out_int = reverse(input_int);
    printf("反转的正数%d\n",out_int);
    return 0; 
}
int reverse(int x){
    int  a=x;
	int num,sum = 0,len = 0, m = 1; 
	/*num：代表数位上的数字，sum：最后的结果，len: 数字长度 m:基本数位，用来转换10,、100、1000等
	*/
		do{
			a /= 10;
			len++;
			if (len > 1)
				m = m * 10;
		}while (a);
		if (x >= 0)
		{
			do {
				num = x % 10;
				if (num > 2&&len>=10)
					return 0;
                else
                    len--;
                if (2147483647 - sum < m* num)
					return 0;
				sum = sum + m * num;
                
				m = m / 10;
				x = x / 10;
			} while (x);
		}
		else
		{
			do {
				num = x % 10;
				if(num < -2 && len >= 10)
					return 0;
                else
                    len--;
                if (-2147483648 - sum > m* num)
					return 0;
				sum = sum + m * num;
				m = m / 10;
				x = x / 10;
			} while (x);
		}	
		return sum;
}

/*------------------------------
学习笔记
该功能主要是对int数的个数不断取余，然后相加
重点需理解下面部分
//pop operation:
pop = x % 10;
x /= 10;

//push operation:
temp = rev * 10 + pop;
rev = temp;

之后是确定反转值的临界问题，前一个数没有溢出，不代表反转后的数不会溢出
---------------------------------*/

