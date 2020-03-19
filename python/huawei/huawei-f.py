#!/usr/bin/env python
# -*- coding: UTF-8 -*-

import json
import requests
from HttpRequest import HttpRequests
import sys
reload(sys)
test = 0

class HWcloud_v1():
    def __init__(self):
        #self.resouce_path = resouce_path
        self.headers = {"content-type": "application/json"}

    def get_iam_token():
        if(test):
            headers = {"content-type": "application/json"}
            try:
                f = open("/home/danoao/文档/test.txt", 'r')
                token_str = f.read().encode('utf-8')
                f.close()
                token_info = json.loads(token_str)
                self.headers["x-auth-token"] = token_info["token"]
                print('读取token成功')
            except:
                rint('读取失败')
        else:
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
            token_req = HttpRequests(take_url, data=json.dumps(data),
            type="POST", headers =self.headers)
            token_info = {
                "token": token_req.get_headers()["X-Subject-Token"],
                "project_id": "cn-north-4",
                "expires_at": "expires_timestamp"
                }
            f = open('/home/danoao/文档/test.txt','w')
            f.write(json.dumps(token_info))
            f.close()
            print("token写入成功")

HWcloud_v1()    
#if if __name__ == "__main__":
    