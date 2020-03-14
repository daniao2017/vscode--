#ifndef _TULING_H
#define _TULING_H
      
#define TR_CMD_MAX_LEN 1024
      
char cmd[TR_CMD_MAX_LEN] = "curl -l -H \"Content-type: application/json\" -X    POST -d '{\"reqType\": 0, \"perception\": {\"inputText\" : {\"text\": \"\"},    \"selfInfo\": {\"location\": {\"city\": \"成都\", \"province\": \"四川\",       \"street\": \"九康环路28号\"}}}, \"userInfo\": {\"apiKey\":                     \"84b4094632274f688bd24decddf2d8e2\", \"userId\": \"0\"}}' http://openapi.      tuling123.com/openapi/api/v2";
      
char* Insert_cmd(char *s1,char *cmd); 
char* Char_to_UTF8(const char *in,char *out);
char* Send_cmd(const char *cmd);
char* Print(const char *out,char *result);
#endif   

