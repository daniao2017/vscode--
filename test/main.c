#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include"tuling.h"

int main(int argc,char *argv[])
{
    if(argc!=2)
    {
        printf("please enter the your question\n");
        return -1;
    }
    char out[TR_CMD_MAX_LEN];
    char *buf;
    char result[TR_CMD_MAX_LEN];
    memset(out,0,sizeof(out));
    memset(result,0,sizeof(result));
    Insert_cmd(cmd,argv[1]);
    Char_to_UTF8(cmd,out);
    buf=Send_cmd(out);
    Print(buf,result);
    printf("question:%s\nresult:%s\n",argv[1],result);
    return 0;
}

