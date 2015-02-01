#! /usr/bin/python

# -*- coding: utf-8 -*-

import time
import urllib2
print time.time()
id = ['s_sh600277', 's_sh600218']
fid = ['RB1505', 'CFF_RE_IF1502']
url = 'http://hq.sinajs.cn/rn=%d&list=%s' % (int(time.time() * 100), 
					     ','.join(id))
f_url = 'http://hq.sinajs.cn/?_=%d&list=%s' % (int(time.time() * 100), 
					     ','.join(fid))
print url
f = urllib2.urlopen(f_url)
sh = "sh"
sz = "sz"
print '\n\n'
for line_src in f.readlines():
	line = line_src.decode("gbk").encode("utf-8")
	left, right = line.split('=')

	print left
	right = right[1 : -3]
	print right

	code = left.split("_")[-1]
	data = right.split(",")

	print "code: ", code
	print "data", data
	
