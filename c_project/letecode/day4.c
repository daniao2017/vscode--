/*
你的朋友正在使用键盘输入他的名字 name。偶尔，
在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。
你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），
那么就返回 True。
*/
#include"stdio.h"
typedef enum 
{
    false = 0, 
    true = 1
}bool;

bool isLongPressedName(char * name,char * typed){
    int n = strlen(name),m=strlen(typed);
    int i =0,j=0;
    while (j<m)
    {
        if(i<n && name[i]==typed[j]){
            i++;
            j++;
        }
        else if(j>0 && typed[j]=typed[j-1])
        {
            j++;
        }
        else
        {
            return false;
        }
        
        
    }
    return i ==n;
    
}