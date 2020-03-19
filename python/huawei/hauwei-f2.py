#!/usr/bin/env python
# -*- coding: UTF-8 -*-

import json
import requests
from HttpRequest import HttpRequests
import sys
reload(sys)
sys.setdefaultencoding( "utf-8" )
headers = {"content-type": "application/json;charset=utf8"}
url = "https://nlp-ext.cn-north-4.myhuaweicloud.com/v1/0629bb1a768026c42fffc00e25759f39/nlu/"
test = 0
def get_token():
    try:
        f = open("/home/danoao/文档/test.txt", 'r')
        token_str = f.read().encode('utf-8')
        f.close()
        token_info = json.loads(token_str)
        global headers
        headers["x-auth-token"] = token_info["token"]
        print('读取token成功')
        
    except:
        print('读取失败')
def classification(content=str):

    call_data={
    
     "content":content,
     "domain":1
    }
    class_url= url + "classification"
    call_req = HttpRequests(class_url, data=json.dumps(call_data),
    type="POST", headers =headers)
    if(call_req.get_code() == 200):
        a = call_req.get_text()
        b= json.loads(a)
        print("连接成功分词资源成功")
        content = b["result"]["content"]
        #print(content)
        label = b["result"]["label"]
        #print(label)
        confidence=b["result"]["confidence"]
        #print(confidence)
    else:
        print(call_req.get_text())
def sentiment(content=str):
    call_data={          
        "content":content
    }
    sentiment_url= url + "sentiment"
    call_req = HttpRequests(sentiment_url, data=json.dumps(call_data),
    type="POST", headers =headers)
    if(call_req.get_code() == 200):
        a = call_req.get_text()
        b= json.loads(a)
        print("连接成功分词资源成功")
        content = b["result"]["content"]
        #print(content)
        label = b["result"]["label"]
        #print(label)
        confidence=b["result"]["confidence"]
        #print(confidence)
    else:
        print(call_req.get_text())

if __name__ == "__main__":
    get_token()
    #classification("你三")
    sentiment("你三")