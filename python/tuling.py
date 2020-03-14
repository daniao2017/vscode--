#!/usr/bin/env python
# -*- coding: UTF-8 -*-

import sys
#import urllib2
import json
import requests
import rospy
from std_msgs.msg import String
reload(sys)
sys.setdefaultencoding('utf-8')
int flag = 0
url = "http://openapi.tuling123.com/openapi/api/v2"

data_input = "测试"

req = {
    "perception":
    {
        "inputText":
        {
            "text": data_input
        },

    },
    "userInfo":
    {
        "apiKey": "7b20d5b3648544948ab5767732a51f34",
        "userId": "123"
    }
}
data_json = json.dumps(req).encode('utf8')
if (flag):
    a = requests.post(url,data_json)  # 使用post请求
    content = (a._content).decode('utf-8')  # 获取返回结果_content属性，解码
    res = json.loads(content)  # 反序列化
    intent_code = res['intent']['code']
    results_text = res['results'][0]['values']['text']
    print(str(intent_code))
    print(results_text)

def tuling_talker():
    pub = Publisher("/voice/xf_tts_topic",String,quue_size=10)
    rospy.init_node('tuling_py',anonymous=True)
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        if(flag):
            hello_str = str(results_text)
            pub.publish(hello_str)
            flag=0
        
        rate.sleep()

if __name__ = '__main__':
    try:
        tuling_talker()
    except rospy.ROSInterruptException:
        pass