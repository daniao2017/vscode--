#!/usr/bin/env python
# -*- coding:utf-8 -*-

import os
import json
from HttpRequest import HttpRequests


class HWCloud():
    def __init__(self, token_file, iam_endpoint, iam_token_uri, option, testFile, resultFile):
        self.token_file = token_file
        self.iam_endpoint = iam_endpoint
        self.iam_token_uri = iam_token_uri
        self.headers = {"content-type": "application/json;charset=utf8"}
        self.option = option
        self.testFile = testFile
        self.resultFile = resultFile
        self.get_iam_token()
        self.NLPAwy()

    def get_iam_token(self):
        '''
        以用户名、密码从IAN换取token并加入headers
        :return:
        '''
        # 从本地文件读取尚在有效期内的token
        if os.path.isfile(self.token_file):
            try:
                f = open(self.token_file, 'r', encoding='utf-8-sig')
                token_str = f.read()
                f.close()
                token_info = json.loads(token_str)
                self.headers["X-Auth-Token"] = token_info["X-Auth-Token"]
                print('读取token成功')
            except:
                pass
        # iam_token_url = self.iam_endpoint + self.iam_token_uri
        # num = 0
        # with open(self.testFile, 'r', encoding='utf-8-sig') as fl, \
        #         open(self.resultFile, 'w', encoding='utf-8-sig') as fs:
        #     for line in fl.read().split('\001'):
        #         num += 1
        #         data = {"content": line}  # 感分析-基础版
        #         req = HttpRequests(iam_token_url, data=json.dumps(data), type="POST", headers=self.headers)
        #         print('第%d条记录，进行情感分析：' % num, req.get_text())
        #         fs.write(str(req.get_text()) + '\n')

    # 分词 WS(word segmentation)
    def NLP_WS(self):
        iam_token_url = self.iam_endpoint + self.iam_token_uri
        num = 0
        with open(self.testFile, 'r', ) as fl, \
                open(self.resultFile, 'w', encoding='utf-8-sig') as fs:
            for line in fl.read().split('\001'):
                num += 1
                data = {"text": line, "pos_switch": 1, "lang": "zh", "criterion": "PKU"}  # 分词、此行标注(pos_switch)
                req = HttpRequests(iam_token_url, data=json.dumps(data), type="POST", headers=self.headers)
                print('第%d条记录情感分析：' % num, req.get_text())
                fs.write(str(req.get_text()) + '\n')

    # 文本相似度 TSim(text similarity)
    def NLP_TSim(self):
        iam_token_url = self.iam_endpoint + self.iam_token_uri
        num = 0
        with open(self.testFile, 'r', encoding='utf-8-sig') as fl, \
                open(self.resultFile, 'w', encoding='utf-8-sig') as fs:
            for line in fl.readlines():
                num += 1
                data = {
                    "text1": line.strip('\n').split('\001')[0],
                    "text2": line.strip('\n').split('\001')[1],
                    "lang": "zh"
                }  # 文本相似度-基础版
                print(data)
                req = HttpRequests(iam_token_url, data=json.dumps(data), type="POST", headers=self.headers)
                print('第%d组文本相似度计算：' % num, req.get_text())
                fs.write(str(req.get_text()) + '\n')

    # 情感分析 EA(emotion Analysis)
    def NLP_EA(self):
        iam_token_url = self.iam_endpoint + self.iam_token_uri
        num = 0
        with open(self.testFile, 'r', encoding='utf-8-sig') as fl, \
                open(self.resultFile, 'w', encoding='utf-8-sig') as fs:
            for line in fl.read().split('\001'):
                num += 1
                data = {"content": line}  # 情感分析-基础版
                req = HttpRequests(iam_token_url, data=json.dumps(data), type="POST", headers=self.headers)
                print('第%d条评论，情感分析：' % num, req.get_text())
                fs.write(str(req.get_text()) + '\n')

    # 命名实体识别（NER）-基础版
    def NLP_NER(self):
        iam_token_url = self.iam_endpoint + self.iam_token_uri
        num = 0
        with open(self.testFile, 'r', encoding='utf-8-sig') as fl, \
                open(self.resultFile, 'w', encoding='utf-8-sig') as fs:
            for line in fl.read().split('\001'):
                num += 1
                data = {"content": line, "lang": "zh"}  # 命名实体识别-基础版
                req = HttpRequests(iam_token_url, data=json.dumps(data), type="POST", headers=self.headers)
                print('第%d条数据，命名实体识别：' % num, req.get_text())
                fs.write(str(req.get_text()) + '\n')

    # 文本分类
    def NLP_TCF(self):
        iam_token_url = self.iam_endpoint + self.iam_token_uri
        num = 0
        with open(self.testFile, 'r', encoding='utf-8-sig') as fl, \
                open(self.resultFile, 'w', encoding='utf-8-sig') as fs:
            for line in fl.readlines():
                num += 1
                data = {"content": line, "domain": 1}  # domain只支持1，广告预测识别。
                req = HttpRequests(iam_token_url, data=json.dumps(data), type="POST", headers=self.headers)
                print('第%d条数据，是否为广告？：' % num, req.get_text())
                fs.write(str(req.get_text()) + '\n')

    # 意图识别
    def NLP_IRC(self):
        iam_token_url = self.iam_endpoint + self.iam_token_uri
        num = 0
        with open(self.testFile, 'r', encoding='utf-8-sig') as fl, \
                open(self.resultFile, 'w', encoding='utf-8-sig') as fs:
            for line in fl.readlines():
                num += 1
                data = {"text": line, "lang": "zh"}
                req = HttpRequests(iam_token_url, data=json.dumps(data), type="POST", headers=self.headers)
                print('第%d条数据，意图识别：' % num, req.get_text())
                fs.write(str(req.get_text()) + '\n')

    # NLP任务工作
    def NLPAwy(self):
        if self.option == 'WS':
            self.NLP_WS()
        elif self.option == 'TSim':
            self.NLP_TSim()
        elif self.option == 'EA':
            self.NLP_EA()
        elif self.option == 'NER':
            self.NLP_NER()
        elif self.option == 'TCF':
            self.NLP_TCF()
        elif self.option == 'IRC':
            self.NLP_IRC()


if __name__ == '__main__':

    token_file = "/home/danoao/文档/test.txt"
    iam_endpoint = "https://nlp-ext.cn-north-4.myhuaweicloud.com"

    # 分词及词性标注-基础版
    # tsim_iam_token_uri = "/v1/**********/nlp-fundamental/segment"
    # option = 'WS'
    # tsim_testFile = "E:\\tsim_test.txt"
    # tsim_resultFile = "E:\\tsimResult.txt"
    # HWCloud(token_file, iam_endpoint, tsim_iam_token_uri, option, tsim_testFile, tsim_resultFile)

    # 情感分析-基础版
    # am_iam_token_uri = "/v1/**********/nlu/sentiment"
    # option = 'EA'
    # ea_testFile = "E:\\ea_test.txt"
    # ea_resultFile = "E:\\eaResult.txt"
    # HWCloud(token_file, iam_endpoint, am_iam_token_uri, option, ea_testFile, ea_resultFile)

    # 文本相似度-基础版
    tsim_iam_token_uri = "/v1/**********/nlp-fundamental/text-similarity"
    option = 'TSim'
    tsim_testFile = "/home/danoao/文档/test1.txt"
    tsim_resultFile = "/home/danoao/文档/test2.txt"
    HWCloud(token_file, iam_endpoint, tsim_iam_token_uri, option, tsim_testFile, tsim_resultFile)