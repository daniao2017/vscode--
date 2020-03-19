#!/usr/bin/python
# -*- coding: UTF-8 -*-
import requests
import json
import base64
 

request_url = "https://aip.baidubce.com/rpc/2.0/ai_custom/v1/classification/daniao"
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

access_token = '24.25d22b2a8ba4fd7c890bc8f1f5b78abd.2592000.1587186635.282335-18925894'
request_url = request_url + "?access_token=" + access_token
# 默认数据格式
data = {'image':img_str, "top_num": 5}
json_mod = json.dumps(data)
res = requests.post(request_url, data=json_mod)
a=json.loads(res.text)
c=a["results"]
print(c)