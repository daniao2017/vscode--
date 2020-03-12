#include<stdio.h>
int main(){
    int Sum,X;
    char Op;
    scanf("%d%c",&Sum,&Op);
    /*输入第一个操作数以及操作符，由于输入无空格，故无需特别处理*/
    while (Op!='=')
    {
        scanf("%d",&X);/*输入下一个操作数*/
        switch(Op){
            case'+':
                Sum += X;
                break;
            case'-':
                break;
            case'*':
                Sum *= X;
                break;
            case'/' :
                if(X==0){
                    printf("除法分数为零！\n");
                    return 0;
                }
                Sum /= X;
                break;
            default:
                printf("非法输入！\n");
                return 0;

        }
        scanf("%c",&Op);/*输入下一个操作符*/
    }
    printf("%d\n",Sum);
    return 0;
}