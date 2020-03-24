#!/usr/bin/python
# -*- coding: UTF-8 -*-

import sys
import pyttsx
reload(sys)
sys.setdefaultencoding("utf-8")
text = 'how are you?'
engine = pyttsx.init()
engine.say(text)
engine.runAndWait()
