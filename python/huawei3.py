#!/usr/bin/env python
# -*- coding: UTF-8 -*-

import json
import requests
from HttpRequest import HttpRequests
headers = {"content-type": "application/json"}
url = "https://iam.cn-north-4.myhuaweicloud.com/v3/auth/tokens"
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

req = HttpRequests(url, data=json.dumps(data), type="POST", headers =headers)
print(req.get_code())
print(req.get_text())

if req.get_code() == 201 and "X-Subject-Token" in req.get_headers():
    print(req.get_headers())

#resp = requests.get('https://iam.cn-north-4.myhuaweicloud.com/v3/auth/tokens', headers=headers)
#data_json = json.dumps(req).encode('utf8')
#a = requests.post(url,data_json,headers=header)  # 使用post请求
#content = (a._content).decode('utf-8')
#print(content)
#res = json.loads(content)  # 反序列化
#intent_code = res['intent']['code']
#results_text = res['results'][0]['values']['text']
#print(str(intent_code))
#print(results_text)'''