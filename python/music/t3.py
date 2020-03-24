#!/usr/bin/python
# -*- coding: UTF-8 -*-

import os

voice_url="http://m10.music.126.net/20200324003823/c523db48269c68aec67007d52e9552ec/ymusic/d548/dbd1/a9aa/f479a367c3be7b27a925c2c924a7a96f.mp3"

os.system('mpg123 -q "%s"' % voice_url)