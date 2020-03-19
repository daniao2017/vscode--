#!/usr/bin/env python
# -*- coding: UTF-8 -*-

import json
import requests
from HttpRequest import HttpRequests
import sys
reload(sys)
#测试
test = 1
sys.setdefaultencoding( "utf-8" )
headers = {"content-type": "application/json"}
take_url = "https://iam.cn-north-4.myhuaweicloud.com/v3/auth/tokens"
url = "https://nlp-ext.cn-north-4.myhuaweicloud.com/v1"
##与project_name 相对
project_id = "0629bb1a768026c42fffc00e25759f39"

def get_iam_token():
    '''
    读取token，用来生成消息头，路径可以自己定义，当时间超时时，可以用
    令test为0,再次生成token

    '''
    if(test):
        headers = {"content-type": "application/json"}
        try:
            f = open("/home/danoao/文档/test.txt", 'r')
            token_str = f.read().encode('utf-8')
            f.close()
            token_info = json.loads(token_str)
            headers["x-auth-token"] = token_info["token"]
            print('读取token成功')
        except:
            rint('读取失败')
    else:
        '''
        生成token的数据，其中，要改三个参数，具体见
        https://support.huaweicloud.com/api-nlp/nlp_03_0050.html
        '''
        data = {
        "auth": {
                "identity": {
                    "methods": [
                        "password"
                    ],
                    "password": {
                        "user": {
                            "name": "daniao2017",
                            "password": "1314520liu",
                            "domain": {
                                "name": "daniao2017"
                            }
                        }
                    }
                },
                "scope": {
                    "project": {
                        "name": "cn-north-4"
                    }
                }
            }
        }
        global headers
        token_req = HttpRequests(take_url, data=json.dumps(data),
        type="POST", headers =headers)
        token_info = {
                "token": token_req.get_headers()["X-Subject-Token"],
                "project_id": "cn-north-4",
                "expires_at": "expires_timestamp"
            }
        f = open('/home/danoao/文档/test.txt','w')
        f.write(json.dumps(token_info))
        f.close()
        print("token写入成功")

def peom(peom_type= "0",acrostic=True,peom_tile = str):
    peom_data =    {
       "type": peom_type,
       "title": peom_tile,
       "acrostic":True
    }
    #拼接资源地址
    peom_url="https://nlp-ext.cn-north-4.myhuaweicloud.com/v1/\
       0629bb1a768026c42fffc00e25759f39/nlg/poem"
    peom_req = HttpRequests(peom_url, data=json.dumps(peom_data),
    type="POST", headers =headers)
    a = peom_req.get_text()
    d = json.loads(a,encoding='utf-8')
    print(d)
    #peom_result = d["peom"]
    #return peom_result

def sentiment():
    sent_data={"conten": "你好啊"}
    sent_url="https://nlp-ext.cn-north-4.myhuaweicloud.com/v1/0629bb1a768026c42fffc00e25759f39/nlu/sentiment"
    sent_req= HttpRequests(sent_url, data=json.dumps(sent_data),
    type="POST", headers =headers)
    a = sent_req.get_text()
    d = json.loads(a,encoding='utf-8')
    #print(headers)
    print(d)



if __name__ == "__main__":
    get_iam_token()
    #result=peom(peom_tile="春天")
    sentiment()
    #print(result)
    



