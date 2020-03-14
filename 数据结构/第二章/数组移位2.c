#include <stdio.h>
#define MAXN 1000
#define Swap(a,b) a^=b,b^=a,a^=b;
/*通过连续三次异或运算交换a与b*/

void RightShift(int Array[],int N,int M);

int main(){
    int Number[MAXN],N,M;
    int i;
    scanf("%d%d",&N,&M);
    for(i=0;i<N;i++)
        scanf("%d",&Number[i]);
    M %= N;/*当M大于等于N时候转化成等价小于N的数*/
    RightShift(Number,N,M);/*循环右移M位小数*/
    for (i=0;i<N-1;i++)
        printf("%d\n",Number[i])
    printf("%d\n",Number[N-1]);
    return 0;
}

void RightShift(int Array[],int N,int M)
{
    int i,j;
    if(M>0 && M<N){
        for ( i = 0; j=N-1; i< j; i++,j--)/*逆转N个数据*/

          Swap(Array[i],Array[j]);
        for ( i = 0; j=M-1;i<j; i++,j--)/*逆转前N个数据*/
            Swap(Array[i],Array[j]);

        for(i=M,j=N-1;i<j;i++,j--)/*逆转后N-M个数据*/
            Swap(Array[i],Array[j]);
        
        
    }
}