#!/usr/bin/python
# -*- coding: UTF-8 -*-
import requests 

# client_id 为官网获取的AK， client_secret 为官网获取的SK
host = 'https://aip.baidubce.com/oauth/2.0/token?grant_type=client_credentials&client_id=HRlxfVI3O9AYcf0PMbx4Gbfe&client_secret=YDGN7KuWP6Emlu915woXYMcGEHy1GwXy'
response = requests.get(host)
if response:
    print(response.json())