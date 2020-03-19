#!/usr/bin/python
# -*- coding: UTF-8 -*-
import requests
import json
import base64
client_id = "HRlxfVI3O9AYcf0PMbx4Gbfe"
client_secret = "YDGN7KuWP6Emlu915woXYMcGEHy1GwXy"
request_url = "https://aip.baidubce.com/rpc/2.0/ai_custom/v1/classification/daniao"
test_token=1
# client_id 为官网获取的AK， client_secret 为官网获取的SK
def get_oken():
    host = "https://aip.baidubce.com/oauth/2.0/token?grant_type=client_credentials&client_id="\
    +client_id +"&client_secret="+client_secret
    token_response = requests.get(host)
    if token_response:
        b=token_response.json()
        token = b["access_token"]
        print("获取token成功")
    else :
        print("获取token失败")
    return token
def getByte(path):
    '''
    首先将图片读入
    由于要发送json，所以需要对byte进行str解码
    具体可见参考文档https://ai.baidu.com/ai-doc/EASYDL/Sk38n3baq
    '''
    with open(path, 'rb') as f:
        img_byte = base64.b64encode(f.read())
    img_str = img_byte
    return img_str
 
img_str = getByte('/home/danoao/图片/1.jpg')
access_token = get_token()
request_url = request_url + "?access_token=" + access_token

data = {'image':img_str, "top_num": 5}
json_mod = json.dumps(data)
res = requests.post(request_url, data=json_mod)
print(res.text)