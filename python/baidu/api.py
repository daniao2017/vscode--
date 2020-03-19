# encoding:utf-8
import urllib2

'''
easydl图像分类
'''

request_url = "https://aip.baidubce.com/rpc/2.0/ai_custom/v1/classification/daniao"

img_src = 'http://wx2.sinaimg.cn/mw690/ac38503ely1fesz8m0ov6j20qo140dix.jpg'
req={
    "image": img_src,
    "top_num": 5
}
params = "{\"image\":\"sfasq35sadvsvqwr5q...\",\"top_num\":\"5\"}"

access_token = '24.b96973b062d3b8a8bd87a04b1581758f.2592000.1587182615.282335-18925894'
request_url = request_url + "?access_token=" + access_token
request = urllib2.Request(url=request_url, data=params)
request.add_header('Content-Type', 'application/json')
response = urllib2.urlopen(request)
content = response.read()
if content:
    print content