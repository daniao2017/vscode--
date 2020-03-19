#include<stdio.h>
void Shift(int  Array[],int N);
#define MAXN 100
int main(){
    int Number[MAXN],N,M;
    int i;
    scanf("%d%d",&N,&M);
    for(i=0;i<N;i++)
        scanf("%d",&Number[i]);
    M %=N; /*将m大于等于n时转化为等价的小于n的数*/
    for(i=0;i<M;i++)
        Shift(Number,N);/*n个元素循环一位*/
    for(i=0;i<N-1;i++) /*打印输出*/
        printf("%d",Number[i]);
    printf("%d\n",Number[i]);
    return 0;
}

void Shift(int  Array[],int N)
{
    int i,ArrayEnd;
    ArrayEnd = Array[N-1];
    for (i=N-1;i>0;i--) /*n个元素循环一位*/
        Array[i]=Array[i-1];
    Array[0]=ArrayEnd;
}