#include<stdio.h>
void swap(int *p1,int *p2);
int main(){
    int a,b;
    int *point_1,*point_2;
    printf("please enter a and b:");
    scanf("%d,%d",&a,&b);
    point_1 = &a;
    point_2 =&b;
    if(a<b) swap(point_1,point_2);
    printf("max=%d,min=%d",a,b);
    return 0;
}

void swap(int *p1,int *p2){
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}