#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/*字符串转换为UTF8格式*/
char* Char_to_UTF8(const char *in, char *out)
{
    char temp[1024] = {0};
    int x = 0;
    unsigned long i;
    while(*in != '\0')
    {
        if(*in == '\\')
        {
            strcpy(temp,in);
            *temp = '0';
            *(temp + 4) = '\0';
            i = strtoul(temp, NULL, 16);
            out[x] = i;
            in += 3;
        }
        else
        {
            out[x] = *in;
        }
        x++;
        in++;
    }
    out[x] = '\0';
    return out;
}

/*将对话插入至cmd中*/
char *Insert_cmd(char *s1, char *s2)
{
    int len1 = 0, len2 = 0, j = 0, len3=110, k = 0,i=0;
    char s4[1024];
    char *s3 = s4;
    if (s1 == NULL)
    return NULL;
    if (s2 == NULL)
    return s1;
    len1 = strlen(s1);
    len2 = strlen(s2);
    if(len3>len1)
    return NULL;
    for (i = 0; i<len3; i++) 
    { 
        j++; 
    }
    for (i= 0; i<len1; i++)
    { 
        s4[k++] = s1[i];
    }

    for (i = 0; i<len2; i++)
    s1[j++] = s2[i];
    for(i=len3;i<len1;i++)
    s1[j++]=s4[i];
    s1[j] = '\0';
    return s1;
}

/*访问图灵机器人*/
char* Send_cmd(const char *cmd)
{
    static char buf[1024];
    memset(buf,0,sizeof(buf));
    FILE *p=popen(cmd,"r");
    if(p==NULL)
    {
        printf("fork failed\n");
        return NULL;
    }
    fgets(buf, sizeof(buf), p);
    return buf;
}

/*提取想要的文字*/
char* Print(const char *out,char *result) 
{
    char ch1[1024];
    memset(ch1,0,sizeof(ch1));
    strcpy(ch1,out);
    char *ch2;
    ch2=result;
    int i=0,j=0;
    while(ch1[i++]!='t');
    while(ch1[i++]!='e');
    while(ch1[i++]!='x');
    while(ch1[i++]!='t');
    while(ch1[i++]!='t');
    while(ch1[i++]!='e');
    while(ch1[i++]!='x');
    while(ch1[i++]!='t');
    i+=3;
    while(ch1[i])
    {
        ch2[j++]=ch1[i++];
    }
    ch2[j-5]='\0';
    return result;
}

