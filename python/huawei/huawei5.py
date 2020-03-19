#!/usr/bin/env python
# -*- coding: UTF-8 -*-


import json
import requests
from HttpRequest import HttpRequests
take_headers = {"content-type": "application/json"}
take_url = "https://iam.cn-north-4.myhuaweicloud.com/v3/auth/tokens"
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

req = HttpRequests(take_url, data=json.dumps(data), type="POST", headers =take_headers)
#print(req.get_code())
token_info = {
                "token": req.get_headers()["X-Subject-Token"],
                "project_id": "cn-north-4",
                "expires_at": "expires_timestamp"
            }
f = open('/home/danoao/文档/test.txt','w')
f.write(json.dumps(token_info))
f.close()
print(req.get_code())
print(req.get_headers())