/*--------------------------
*给定一个整数数组 nums 和一个目标值 target，
请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
如
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
----------------------------*/

#include <stdlib.h>
#include <stdio.h>
//int *twoSum(int * nums,int numsSize,int target,int *returnSize);

void main() {
    //nums = [2, 7, 11, 15];
    //int target = 9;
    //int *returnSize = 2;
    //test = twoSum(nums,4,target,2);
    printf("hello world\n");
}

int *twoSum(int * nums,int numsSize,int target,int *returnSize){
    for(int i =0;i<numsSize;++i){
        for(int j= j+1;j<numsSize;++j){
            if(nums[i]+nums[j]==target){
                int* ret =malloc(sizeof(int)*2);
                ret[0]=i,ret[1]=j;
                *returnSize = 2;
                return ret;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
