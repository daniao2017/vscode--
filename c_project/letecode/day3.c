/*
给定一个按非递减顺序排序的整数数组 A，
返回每个数字的平方组成的新数组，要求也按非递减顺序排序。
如:
输入：[-4,-1,0,3,10]
输出：[0,1,9,16,100]
*/
#include<stdio.h>
#include <stdlib.h>
int cmp(const void* _a, const void* _b);
int* sortedSquares(int* A, int ASize, int* returnSize);
int main(){
    int test[5] = {-4,-1,0,3,10};
    int * print_out;
    int a[] ={5} ;
    int b = 5;
    print_out = sortedSquares(test,b,a);
    printf("输出数组\n");
    for(int i=0;i<b;i++){
        printf("%d\n",print_out[i]);
    }
    
    
}

int cmp(const void* _a, const void* _b) {
    int a = *(int*)_a, b = *(int*)_b;
    return a - b;
}

int* sortedSquares(int* A, int ASize, int* returnSize) {
    (*returnSize) = ASize;
    int* ans = malloc(sizeof(int) * ASize);
    for (int i = 0; i < ASize; ++i) {
        ans[i] = A[i] * A[i];
    }
    qsort(ans, ASize, sizeof(int), cmp);
    return ans;
}